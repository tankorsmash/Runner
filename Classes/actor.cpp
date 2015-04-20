#include "actor.h"

USING_NS_CC;

Actor::Actor(std::string sprite_path, Level* lvl, bool is_obstacle) : BaseNode(sprite_path)
{
    b2BodyDef body_def = b2BodyDef();

    this->is_obstacle = is_obstacle;
    if (is_obstacle)
    {
        body_def.type = b2_staticBody;
    }
    else
    {
        body_def.type = b2_dynamicBody;
    };
    body_def.position.Set(250 / PTM_RATIO, 150 / PTM_RATIO);
    body_def.fixedRotation = true;
    body_def.userData = this->sprite;
    _body = lvl->_world->CreateBody(&body_def);

    //b2CircleShape body_shape;
    //body_shape.m_radius = 16.0 / PTM_RATIO;

    Vec2 sprite_size = this->sprite->getContentSize();
    cocos2d::log("%f %f", sprite_size.x, sprite_size.y);

    b2PolygonShape body_shape;
    body_shape.SetAsBox(sprite_size.x/PTM_RATIO/2, sprite_size.y/PTM_RATIO/2);

    b2FixtureDef actor_fixture;
    actor_fixture.shape = &body_shape;
    actor_fixture.density = 1.0f;
    actor_fixture.friction = 1.0f;
    actor_fixture.restitution = 0.1f;

    _body->CreateFixture(&actor_fixture);


}
void Actor::move(float x, float y)
{
    b2Vec2 force = b2Vec2(x, y);
    this->_body->ApplyLinearImpulse(force, _body->GetPosition(), true);
}

void Actor::move_up()
{
    this->move(0, 4);
};

void Actor::move_right()
{
    this->move(2, 0);
};

void Actor::move_left()
{
    this->move(-2, 0);
};

void Actor::set_crouch(bool val)
{
    this->is_crouched = val;

    b2Fixture* fix = &this->_body->GetFixtureList()[0];
    this->_body->DestroyFixture(fix);

    auto sprite_size = this->sprite->getContentSize();

    b2PolygonShape body_shape;
    b2FixtureDef actor_fixture;

    if (this->is_crouched)
    {
        this->sprite->setScale(0.5);

        body_shape.SetAsBox(sprite_size.width / 2 / 2 / PTM_RATIO, sprite_size.height / 2 / 2 / PTM_RATIO);

        actor_fixture.shape = &body_shape;
        actor_fixture.density = 1.0f;
        actor_fixture.friction = 1.0f;
        actor_fixture.restitution = 0.1f;
    }
    else
    {
        this->sprite->setScale(1.0);
        body_shape.SetAsBox(sprite_size.width / 2 / PTM_RATIO, sprite_size.height / 2 / PTM_RATIO);

        actor_fixture.shape = &body_shape;
        actor_fixture.density = 1.0f;
        actor_fixture.friction = 1.0f;
        actor_fixture.restitution = 0.1f;
    };

    _body->CreateFixture(&actor_fixture);
    _body->ResetMassData();
};

bool Actor::toggle_crouch()
{
    this->set_crouch(!this->is_crouched);
    return this->is_crouched;
};

void Actor::jump()
{
    if (! this->is_jumping)
    {
        this->move_up();
        this->is_jumping = true;
    };
};

void Actor::update(float dt)
{
    auto velocity = this->_body->GetLinearVelocity();
    if (velocity.x > 0.5)
    {
        this->sprite->setFlippedX(false);
    }
    else if (velocity.x < -0.5)
    {
        this->sprite->setFlippedX(true);
    };

    b2Vec2 body_pos = this->_body->GetPosition();
    float32 adj_y = body_pos.y*PTM_RATIO;
    if (adj_y < this->jump_threshold)
    {
        this->is_jumping = false;
    }

};
