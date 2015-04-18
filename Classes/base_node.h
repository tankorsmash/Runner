#pragma once
#ifndef BASE_NODE_H
#define BASE_NODE_H

#define PTM_RATIO 32.0

#include "cocos2d.h"

class BaseNode : public cocos2d::Node
{

    public:
        cocos2d::Sprite* sprite;
        BaseNode(std::string sprite_path);

};
#endif
