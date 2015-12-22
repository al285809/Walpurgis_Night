#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Characters\Valkyrie.h"
#include "Characters\Enemies.h"
#include "Cathedral.h"

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
private:
	EventKeyboard::KeyCode _pressedKey;
	Label *_labelSit;
	Label *_labelHour;
	PhysicsWorld *mWorld;
	
public:
	enum direction;

	direction currentDirection;
	static int _Situation;
	static std::string _valkyrie;
	static int _hour;
	static int _minute;
	static int _healthPoints;

	Valkyrie* _Valkyrie;


	Cathedral *cathedral;
	//Enemies* enemy;

	static cocos2d::Scene* createScene();

	void update(float dt);

	void goToPauseScene(Ref *pSender);
	void goToGameOverScene(Ref *pSender);

	void Timer(float dt);

	float time;
	float timeDif;

	virtual bool init();

	//void showItems();

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);

	void setPhysicsWorld(PhysicsWorld *world);
	bool onContactBegin(PhysicsContact &contact);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__

