#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "base_node.h"

class Level : public BaseNode
{
    public:
        Level(std::string sprite_path) : BaseNode(sprite_path){};
};
#endif
