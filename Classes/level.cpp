#include "level.h"

Level::Level(std::string sprite_path) : BaseNode(sprite_path)
{
    b2Vec2 gravity = b2Vec2(0.0f, -8.0f);
    this->_world = new b2World(gravity);

    b2BodyDef ground_bdef;
    ground_bdef.position.Set(0, (640-577-8)/PTM_RATIO);
    //ground_bdef.position.Set(0, 0);

    b2Body* ground_body = _world->CreateBody(&ground_bdef);
    b2EdgeShape ground_edge;

    b2FixtureDef ground_fixture_def;
	ground_fixture_def.restitution = 0.0f;
    ground_fixture_def.shape = &ground_edge;

    //floor
    ground_edge.Set(b2Vec2(0, 0), b2Vec2(640/PTM_RATIO, 0));
    ground_body->CreateFixture(&ground_fixture_def);

    //right wall
    ground_edge.Set(b2Vec2(640/PTM_RATIO, 0), b2Vec2(640/PTM_RATIO, 640/PTM_RATIO));
    ground_body->CreateFixture(&ground_fixture_def);

    //left wall
    ground_edge.Set(b2Vec2(0, 0), b2Vec2(0, 640/PTM_RATIO));
    ground_body->CreateFixture(&ground_fixture_def);

    //top
    ground_edge.Set(b2Vec2(0, 640/PTM_RATIO), b2Vec2(640/PTM_RATIO, 640/PTM_RATIO));
    ground_body->CreateFixture(&ground_fixture_def);

};
