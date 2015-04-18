#include "HelloWorldScene.h"

#include "GameLayer.h"
#include "actor.h"
#include "level.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
#ifdef _WIN32
    FUNC_INIT_WIN32(HelloWorld);
#else
    FUNC_INIT(HelloWorld);
#endif
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

	level_1 = new Level("level_1.png");
	//level_1->setAnchorPoint(Vec2(0.5, 0.5));
    level_1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(level_1);


	Actor* player = new Actor("runner.png", level_1);
	//player->setAnchorPoint(Vec2(0.5, 0.5));
	level_1->sprite->addChild(player);

	// this->schedule(schedule_selector(HelloWorld::tick));
    
    return true;
}

void HelloWorld::update(float dt)
{
	Rect bbox = this->level_1->sprite->boundingBox();

	this->level_1->_world->Step(dt, 10, 10);
	for (b2Body* b = this->level_1->_world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			Sprite* sprite = (Sprite*)b->GetUserData();
			b2Vec2 b_pos = b->GetPosition();
			Vec2 new_pos = Vec2(
				b_pos.x * PTM_RATIO,
				b_pos.y * PTM_RATIO);
			sprite->setPosition(new_pos);
			//sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
		}

	}

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{

    GameLayer::onTouchBegan(touch, event);

    //this is how you'd use this
    // if (touch_in_node(some_sprite_instance, touch))
    // {
    //     do_something();
    //     return false;
    // }


    return true; //what does this do? answer: determines whether the touch keeps going or something
};

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *pEvent)
{
    if(keyCode == EventKeyboard::KeyCode::KEY_BACK || keyCode == EventKeyboard::KeyCode::KEY_ESCAPE) 
    {
        this->menuCloseCallback(NULL);
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_Q || keyCode == EventKeyboard::KeyCode::KEY_1) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_E || keyCode == EventKeyboard::KeyCode::KEY_3) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_R || keyCode == EventKeyboard::KeyCode::KEY_4) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_F) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_C) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_TAB) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_Z) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_V) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_S) 
    {
    }
    else if(keyCode == EventKeyboard::KeyCode::KEY_D) 
    {
    }
}
