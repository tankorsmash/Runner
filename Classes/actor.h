#pragma once
#ifndef ACTOR_H
#define ACTOR_H

#include "base_node.h"
#include "level.h"
#include "Box2D/Box2D.h"

class Actor : public BaseNode
{
    public:
        Actor(std::string sprite_path, Level* lvl, bool is_obstacle);

        //if true, don't move
        bool is_obstacle = false;

        bool is_crouched = false;
        void set_crouch(bool val);
        bool toggle_crouch();

        bool is_jumping = false;
        float jump_threshold = 80.0f;

        void move(float x, float y);
        void move_right();
        void move_left();
        void move_up();
        void jump();

        void update(float dt);
};
#endif
