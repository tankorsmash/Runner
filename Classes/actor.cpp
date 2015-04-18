#include "actor.h"

USING_NS_CC;

Actor::Actor(std::string sprite_path)
{
	
	this->sprite = Sprite::create(sprite_path);
	this->addChild(this->sprite);
}