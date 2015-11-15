#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;
	String _sceneId;

public:
	static cocos2d::Scene* createScene();

	void goToPauseScene(Ref *pSender);
	void goToGameOverScene(Ref *pSender);

	void moveScene();

	virtual bool init();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__

