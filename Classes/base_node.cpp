#include "base_node.h"

USING_NS_CC;

BaseNode::BaseNode(std::string sprite_path)
{
	this->sprite = Sprite::create(sprite_path);
    if (this->sprite == NULL)
    {
        std::stringstream ss;
        ss << sprite_path << " is probably missing, this'll cause problems. Check the runner/Resources folder for it." << std::endl;
        cocos2d::log("%s", ss.str().c_str());
    };
	//this->sprite->setAnchorPoint(Vec2(0.5, 0.5));
	this->sprite->setPosition(0, 0);
	this->addChild(this->sprite);
}

void BaseNode::SetBodyPosition(int x, int y)
{ 
	if (this->_body != NULL)
	{
		auto old_pos = this->_body->GetPosition();
		this->_body->SetTransform(b2Vec2((x / PTM_RATIO), (y / PTM_RATIO)), this->_body->GetAngle());
	};
}

void BaseNode::SetBodyPositionRelative(int x, int y)
{ 
	if (this->_body != NULL)
	{
        auto old_pos = this->_body->GetPosition();
        this->SetBodyPosition(old_pos.x*PTM_RATIO + x, old_pos.y*PTM_RATIO + y);
	};
}
