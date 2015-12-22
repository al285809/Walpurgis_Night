#ifndef __PAUSE_SCENE_H__
#define __PAUSE_SCENE_H__

#include "cocos2d.h"
#include "Characters\Valkyrie.h"
#include "Items.h"

USING_NS_CC;

class PauseScene : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;

public:
	static cocos2d::Scene* createScene();

	void resumeGameScene(Ref *pSender);
	void goToMainMenu(Ref *pSender);
	void retryGameScene(Ref *pSender);

	virtual bool init();


	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	// implement the "static create()" method manually
	CREATE_FUNC(PauseScene);
};

#endif // __HELLOWORLD_SCENE_H__