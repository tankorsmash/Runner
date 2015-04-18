#pragma once
#ifndef ACTOR_H
#define ACTOR_H

#include "base_node.h"

class Actor : public BaseNode
{
    public:
        Actor(std::string sprite_path) : BaseNode(sprite_path){};
};
#endif
