#include "GameScene.h"
#include "GameOverScene.h"
#include "PauseScene.h"
#include "StartScene.h"
#include "Valkyrie.h"
#include <string>
#include "Data.h"

USING_NS_CC;

int GameScene::_Situation;
std::string GameScene::_valkyrie;
int GameScene::_hour;
int GameScene::_minute;
int GameScene::_healthPoints;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Point origin = Director::sharedDirector()->getVisibleOrigin();
	Size size = Director::sharedDirector()->getVisibleSize(); 

	testSprite = Sprite::create("images/GameScreen/Valquiria.png");
	testSprite->setPosition(Point(size.width / 2 + origin.x, size.height / 2 + origin.y));

	this->addChild(testSprite, 5);

	float playfield_width = size.width * 2.0;
	float playfield_height = size.height * 2.0;

	this->runAction(Follow::create(testSprite, Rect(size.width / 2 + origin.x - playfield_width / 2, size.height / 2 + origin.y - playfield_height / 2, playfield_width, playfield_height)));

	Size _visibleSize = Director::getInstance()->getVisibleSize();

	GameScene::_Situation = CCUserDefault::sharedUserDefault()->getIntegerForKey("situation");
	//GameScene::_valkyrie = Valkyrie::Vname;
	GameScene::_hour = CCUserDefault::sharedUserDefault()->getIntegerForKey("hour");
	GameScene::_minute = CCUserDefault::sharedUserDefault()->getIntegerForKey("minute");
	GameScene::_healthPoints = CCUserDefault::sharedUserDefault()->getIntegerForKey("HP");
	
	//////////////////////////////
	// 2. create background
	auto background = Sprite::create("images/GameScreen/portadaCaca.png");

	background->setPosition(Point((_visibleSize.width / 2),
		(_visibleSize.height / 2)));
	addChild(background, 0);

	//valkyrie = new Valkyrie(this);
	//valkyrie->setPosition(Point(valkyrie->posX, valkyrie->posY));

	//////////////////////////////
	// 3. prepare keys and buttons
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//////////////////////////////
	// 4. set situation

	__String *text = __String::createWithFormat("%d", GameScene::_Situation);
	_labelSit = Label::createWithTTF(text->getCString(), "fonts/MArker Felt.ttf", 24);

	_labelSit->setPosition(Vec2(_visibleSize.width - 150, _visibleSize.height - 30));
	addChild(_labelSit, 3);

	__String *hourToDisplay = __String::createWithFormat("%.2i:%.2i", GameScene::_hour, GameScene::_minute);
	_labelHour = Label::createWithTTF(hourToDisplay->getCString(), "fonts/MArker Felt.ttf", 24);

	_labelHour->setPosition(Vec2(_visibleSize.width / 2, 50));
	addChild(_labelHour, 3);

	//////////////////////////////
	// 5. start time

	time = 0;
	this->schedule(schedule_selector(GameScene::Timer), 0.01);

	return true;
}

void GameScene::moveScene() {

}

void GameScene::Timer(float dt) {
	time += dt;
	if (time >= 15) {
		GameScene::_minute++;
		if (GameScene::_minute == 60) {
			GameScene::_minute = 0;
			GameScene::_hour++;
			if (GameScene::_hour == 24) GameScene::goToGameOverScene(this);
		}
		time = 0;
	}
	__String *hour = __String::createWithFormat("%.2i:%.2i", GameScene::_hour, GameScene::_minute);
	_labelHour->setString(hour->getCString());
}

void GameScene::goToPauseScene(Ref *pSender) {
	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(scene);
}
void GameScene::goToGameOverScene(Ref *pSender) {
	auto scene = GameOver::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			testSprite->setPositionX(testSprite->getPositionX() + 5.0);
			_labelHour->setPositionX(_labelHour->getPositionX() + 5.0);
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			testSprite->setPositionX(testSprite->getPositionX() - 5.0);
			_labelHour->setPositionX(_labelHour->getPositionX() - 5.0);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			testSprite->setPositionY(testSprite->getPositionY() + 5.0);
			_labelHour->setPositionY(_labelHour->getPositionY() + 5.0);
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			testSprite->setPositionY(testSprite->getPositionY() - 5.0);
			_labelHour->setPositionY(_labelHour->getPositionY() - 5.0);
			break;
		case EventKeyboard::KeyCode::KEY_SPACE:
			//CC_CALLBACK_1(MainMenu::goToStartScene, this);
			goToPauseScene(this);
			break;
		case EventKeyboard::KeyCode::KEY_Q:
			//CC_CALLBACK_1(MainMenu::goToStartScene, this);
			GameScene::_Situation ++;
			__String *text = __String::createWithFormat("%d",
				GameScene::_Situation);
			_labelSit->setString(text->getCString());
			break;
	
	}
}
void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}
