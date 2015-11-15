#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

const int POD_STEP_MOVE = 10;

class MainMenu : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;

public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void goToStartScene(Ref *pSender);
	void goToCreditsScene(Ref *pSender);
	void goToInstructionsScene(Ref *pSender);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	// implement the "static create()" method manually
	CREATE_FUNC(MainMenu);

	
};

#endif // __MAINMENU_SCENE_H__