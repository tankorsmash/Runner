#pragma once
#ifndef ACTOR_H
#define ACTOR_H

#include "base_node.h"
#include "level.h"
#include "Box2D/Box2D.h"

class Actor : public BaseNode
{
    public:
        Actor(std::string sprite_path, Level* lvl) : BaseNode(sprite_path)
		{
			b2BodyDef body_def = b2BodyDef();
			body_def.type = b2_dynamicBody;
			body_def.position.Set(25 / PTM_RATIO, 100 / PTM_RATIO);
			body_def.userData = this->sprite;
			
			//b2CircleShape circle;
			//circle.m_radius = 32.0 / PTM_RATIO;

			b2PolygonShape circle;
			circle.SetAsBox(32/PTM_RATIO, 32/PTM_RATIO);


			b2FixtureDef ballshapedef;
			ballshapedef.shape = &circle;
			ballshapedef.density = 1.0f;
			ballshapedef.friction = 0.2f;
			ballshapedef.restitution = 0.8f;

			_body = lvl->_world->CreateBody(&body_def);
			_body->CreateFixture(&ballshapedef);

		};

		b2Body* _body;
};
#endif
