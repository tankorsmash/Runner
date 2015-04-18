#pragma once
#ifndef BASE_NODE_H
#define BASE_NODE_H

#include "cocos2d.h"

class BaseNode : public cocos2d::Node
{

    public:
        cocos2d::Sprite* sprite;
        BaseNode(std::string sprite_path);

};
#endif
