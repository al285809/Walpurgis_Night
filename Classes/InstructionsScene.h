#ifndef __INSTRUCTIONS_SCENE_H__
#define __INSTRUCTIONS_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class InstructionsScene : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;

public:
	static cocos2d::Scene* createScene();

	void goToMainMenu(Ref *pSender);

	virtual bool init();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	// implement the "static create()" method manually
	CREATE_FUNC(InstructionsScene);
};

#endif

