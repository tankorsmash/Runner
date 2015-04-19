#include "actor.h"

Actor::Actor(std::string sprite_path, Level* lvl) : BaseNode(sprite_path)
{
    b2BodyDef body_def = b2BodyDef();
    body_def.type = b2_dynamicBody;
    body_def.position.Set(250 / PTM_RATIO, 150 / PTM_RATIO);
    body_def.userData = this->sprite;

    //b2CircleShape circle;
    //circle.m_radius = 16.0 / PTM_RATIO;

    b2PolygonShape circle;
    circle.SetAsBox(16/PTM_RATIO, 16/PTM_RATIO);


    b2FixtureDef ballshapedef;
    ballshapedef.shape = &circle;
    ballshapedef.density = 1.0f;
    ballshapedef.friction = 0.6f;
    ballshapedef.restitution = 0.5f;

    _body = lvl->_world->CreateBody(&body_def);
    _body->CreateFixture(&ballshapedef);


}
void Actor::move(float x, float y)
{
    b2Vec2 force = b2Vec2(x, y);
    this->_body->ApplyLinearImpulse(force, _body->GetPosition(), true);
}

void Actor::move_up()
{
    this->move(0, 2);
};

void Actor::move_right()
{
    this->move(2, 0);
};

void Actor::move_left()
{
    this->move(-2, 0);
};

void Actor::update(float dt)
{
    auto inertia = this->_body->GetLinearVelocity();
    cocos2d::log("%f %f", inertia.x, inertia.y);
    if (inertia.x >= 0)
    {
        this->sprite->setFlippedX(false);
    }
    else if (inertia.x < 0)
    {
        this->sprite->setFlippedX(true);
    }
};
