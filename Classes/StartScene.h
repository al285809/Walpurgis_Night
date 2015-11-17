#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class StartScene : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;

public:
	static cocos2d::Scene* createScene();

	void goToMainMenu(Ref *pSender);
	void goToGameScene(Ref *pSender);

	virtual bool init();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	void setDefaultInformation();

	// implement the "static create()" method manually
	CREATE_FUNC(StartScene);
};

#endif