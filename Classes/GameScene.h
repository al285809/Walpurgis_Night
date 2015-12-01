#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;
	Label *_labelSit;
	Label *_labelHour;
	static int _healthPoints;
	Sprite *testSprite;

public:
	static int _Situation;
	static std::string _valkyrie;
	static int _hour;
	static int _minute;
	//Valkyrie *valkyrie;

	static cocos2d::Scene* createScene();

	void goToPauseScene(Ref *pSender);
	void goToGameOverScene(Ref *pSender);

	void moveScene();
	void Timer(float dt);

	float time;

	virtual bool init();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__

