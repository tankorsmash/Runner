#include "cocos2d.h"

class BaseNode : public cocos2d::Node
{

    public:
        cocos2d::Sprite* sprite;
        BaseNode(std::string sprite_path);

};
