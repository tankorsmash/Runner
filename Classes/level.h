#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "base_node.h"
#include "Box2D/Box2D.h"

class Level : public BaseNode
{
    public:
        b2World* _world;
        Level(std::string sprite_path) ;
};
#endif
