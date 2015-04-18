#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameLayer.h"
#include <level.h>

class HelloWorld : public GameLayer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

	void update(float dt);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent);
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    virtual bool init();
    
	Level* level_1;
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif // __HELLOWORLD_SCENE_H__
