#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameLayer.h"
#include <level.h>

class Actor;

class HelloWorld : public GameLayer
{
    public:
        //start of generalized layer stuff
        static cocos2d::Scene* createScene();

        void update(float dt);
        void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent);
        virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

        CREATE_FUNC(HelloWorld);

        virtual bool init();

        //class specific stuff from here on out
        Level* level_1;
        void menuCloseCallback(cocos2d::Ref* pSender);

        Actor* player;
        Actor* brick;

};

#endif // __HELLOWORLD_SCENE_H__
