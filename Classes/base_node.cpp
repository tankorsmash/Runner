#include "base_node.h"

USING_NS_CC;

BaseNode::BaseNode(std::string sprite_path)
{
	this->sprite = Sprite::create(sprite_path);
	//this->sprite->setAnchorPoint(Vec2(0.5, 0.5));
	this->sprite->setPosition(0, 0);
	this->addChild(this->sprite);
}
