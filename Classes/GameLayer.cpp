#include "GameLayer.h"

USING_NS_CC;


std::string GameLayer::menu_font = "UN INIT";
int GameLayer::menu_fontsize = 0;
int GameLayer::menu_heightdiff = 0;

bool GameLayer::touch_in_node(Node* target, cocos2d::Touch* touch)
{
    if (target->getBoundingBox().containsPoint(this->convertTouchToNodeSpace(touch))) 
    {
        return true;
    }
    return false;
};

bool GameLayer::vec2_in_node(Node* target, cocos2d::Vec2 pos)
{
    if (target->getBoundingBox().containsPoint(pos)) 
    {
        return true;
    }
    return false;
};

bool GameLayer::vec2_in_rect(Rect* rect, cocos2d::Vec2 pos)
{
    if (rect->containsPoint(pos))
    {
        return true;
    }
    return false;
}

bool GameLayer::init()
{
    isTouchDown = false;

    initialTouchPos[0] = 0;
    initialTouchPos[1] = 0;

    return true;
};

void GameLayer::update(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    if (true == isTouchDown)
    {
        if (initialTouchPos[0] - currentTouchPos[0] > visibleSize.width * 0.05)
        {
            this->onSwipeLeft(dt);
            isTouchDown = false;
        }
        else if (initialTouchPos[0] - currentTouchPos[0] < - visibleSize.width * 0.05)
        {
            this->onSwipeRight(dt);
            isTouchDown = false;
        }
        else if (initialTouchPos[1] - currentTouchPos[1] > visibleSize.width * 0.05)
        {
            this->onSwipeDown(dt);
            isTouchDown = false;
        }
        else if (initialTouchPos[1] - currentTouchPos[1] < - visibleSize.width * 0.05)
        {
            this->onSwipeUp(dt);
            isTouchDown = false;
        }
        else if (initialTouchPos[0] == currentTouchPos[0] && initialTouchPos[1] == currentTouchPos[1])
        {
            // CCLOG("no move?");
        }
    }
};

float GameLayer::sx( float x)
{

    // auto drs = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    auto frs = Director::getInstance()->getOpenGLView()->getFrameSize();
    return x * (frs.width / 960.0);
};

float GameLayer::sy( float y)
{

    // auto drs = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    auto frs = Director::getInstance()->getOpenGLView()->getFrameSize();
    return y * (frs.height / 640.0);
};

bool GameLayer::onTouchBegan(Touch *touch, Event *event)
{
    initialTouchPos[0] = touch->getLocation().x;
    initialTouchPos[1] = touch->getLocation().y;
    currentTouchPos[0] = touch->getLocation().x;
    currentTouchPos[1] = touch->getLocation().y;

    isTouchDown = true;

    return true;
}

void GameLayer::onTouchMoved(Touch *touch, Event *event)
{
    currentTouchPos[0] = touch->getLocation().x;
    currentTouchPos[1] = touch->getLocation().y;
}

void GameLayer::onTouchEnded(Touch *touch, Event *event)
{
    isTouchDown = false;
}

void GameLayer::onTouchCancelled(Touch *touch, Event *event)
{
    onTouchEnded(touch, event);
}

void GameLayer::onSwipeLeft(float dt)
{
    cocos2d::log("SWIPED LEFT");
};

void GameLayer::onSwipeUp(float dt)
{
    CCLOG("SWIPED UP");
};

void GameLayer::onSwipeRight(float dt)
{
    CCLOG("SWIPED RIGHT");
};

void GameLayer::onSwipeDown(float dt)
{
    CCLOG("SWIPED DOWN");
};

void GameLayer::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
};


cocos2d::ui::ScrollView* GameLayer::create_center_scrollview()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto scroll = ui::ScrollView::create();
    //scroll->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    int scroll_w = sx(600);
    int scroll_h = sy(400);
    Size scroll_size = Size(scroll_w, scroll_h);
    scroll->setSize(scroll_size);
    scroll->setAnchorPoint(Vec2(0.5, 0.5));
    scroll->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2));
    scroll->setDirection(ui::ScrollView::Direction::VERTICAL);
    this->addChild(scroll);
    //scroll->setBackGroundColor(Color3B::GREEN);

    auto container_size = Size(scroll_w, scroll_h*3);
    scroll->setInnerContainerSize(container_size);
    scroll->setLayoutType(ui::Layout::Type::VERTICAL);

    return scroll;
}

cocos2d::ui::Button* GameLayer::create_button(std::string text, cocos2d::ccMenuCallback cb)
{
    auto param = ui::LinearLayoutParameter::create();
    param->setGravity(ui::LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
    param->setMargin(ui::Margin(0, menu_fontsize/2, 0, 0));

    auto btn = ui::Button::create();
    btn->setTitleFontName(menu_font);
    btn->setTitleFontSize(menu_fontsize);
    btn->setTitleColor(Color3B::GREEN);
    btn->setLayoutParameter(param);
    btn->setTouchEnabled(true);
    btn->setPressedActionEnabled(true);

    btn->addTouchEventListener([this,cb](Ref* ref, ui::Widget::TouchEventType event)
            {
            if (event == ui::Widget::TouchEventType::ENDED){ cb(NULL); }
            });
    btn->setTitleText(text);

    return btn;

};
