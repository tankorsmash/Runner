#include "actor.h"

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
