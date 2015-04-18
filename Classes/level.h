#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "base_node.h"
#include "Box2D/Box2D.h"

class Level : public BaseNode
{
    public:
		b2World* _world;
        Level(std::string sprite_path) : BaseNode(sprite_path)
        {
			b2Vec2 gravity = b2Vec2(0.0f, -8.0f);
			this->_world = new b2World(gravity);
			
        };
};
#endif
