#include "base_node.h"

USING_NS_CC;

BaseNode::BaseNode(std::string sprite_path)
{
	this->sprite = Sprite::create(sprite_path);
	this->addChild(this->sprite);
}
