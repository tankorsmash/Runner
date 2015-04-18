
#include "cocos2d.h"
class Actor : public cocos2d::Node
{

public:
	cocos2d::Sprite* sprite;
	Actor(std::string sprite_path);

};