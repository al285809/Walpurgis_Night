#include "GameScene.h"
#include "GameOverScene.h"
#include "PauseScene.h"
#include "StartScene.h"
#include "Characters\Valkyrie.h"
#include <string>
#include "Data.h"
#include "Characters\Enemies.h"
#include "Items.h"
#include "Cathedral.h"

USING_NS_CC;

int GameScene::_Situation;
std::string GameScene::_valkyrie;
int GameScene::_hour;
int GameScene::_minute;
int GameScene::_healthPoints;

enum GameScene::direction { RIGHT, LEFT, UP, DOWN };

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());

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

	float playfield_width = size.width * 2.0;
	float playfield_height = size.height * 2.0;

	Size _visibleSize = Director::getInstance()->getVisibleSize();

	currentDirection = GameScene::direction::DOWN;

	GameScene::_Situation = CCUserDefault::sharedUserDefault()->getIntegerForKey("situation");
	//GameScene::_valkyrie = Valkyrie::Vname;
	GameScene::_hour = CCUserDefault::sharedUserDefault()->getIntegerForKey("hour");
	GameScene::_minute = CCUserDefault::sharedUserDefault()->getIntegerForKey("minute");
	GameScene::_healthPoints = CCUserDefault::sharedUserDefault()->getIntegerForKey("HP");
	
	//////////////////////////////
	// 2. create background
	cathedral = new Cathedral(this, _visibleSize.width / 2, _visibleSize.height / 2);

	_Valkyrie = new Valkyrie(this, _visibleSize.width/2, _visibleSize.height/2);

	//this->runAction(Follow::create(_Valkyrie, Rect::ZERO));


	//////////////////////////////
	// 3. prepare keys and buttons
	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//////////////////////////////
	// 4. set situation

	__String *text = __String::createWithFormat("HP: %i", GameScene::_healthPoints);
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
	timeDif = 0;
	this->scheduleUpdate();
	this->schedule(schedule_selector(GameScene::Timer), 0.01);

	//////////////////////////////
	// 5. prepare collisions

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	return true;
}

void GameScene::update(float dt) {
	if (_Valkyrie->right) {
		_Valkyrie->down = false;
		_Valkyrie->left = false;
		_Valkyrie->up = false;
		if (!cathedral->collidesValkyrie(_Valkyrie->Rrange))
		{
			currentDirection = direction::RIGHT;
			cathedral->moveSpace(-2, 0);
		}
	}

	if (_Valkyrie->left) {
		_Valkyrie->right = false;
		_Valkyrie->down = false;
		_Valkyrie->up = false;
		if (!cathedral->collidesValkyrie(_Valkyrie->Lrange))
		{
			currentDirection = direction::LEFT;
			cathedral->moveSpace(2, 0);
		}
	}

	if (_Valkyrie->up) {
		_Valkyrie->right = false;
		_Valkyrie->left = false;
		_Valkyrie->down = false;
		if (!cathedral->collidesValkyrie(_Valkyrie->Urange))
		{
			currentDirection = direction::UP;
			cathedral->moveSpace(0, -2);
		}
	}

	if (_Valkyrie->down) {
		_Valkyrie->right = false;
		_Valkyrie->left = false;
		_Valkyrie->up = false;
		if (!cathedral->collidesValkyrie(_Valkyrie->Drange))
		{
			currentDirection = direction::DOWN;
			cathedral->moveSpace(0, 2);
		}
	}


	/*{ 
		this->removeChild(cathedral->enemies, true);
	}*/

	if (!cathedral->enemies->collidesValkyrie(_Valkyrie->Rrange, this) &&
		!cathedral->enemies->collidesValkyrie(_Valkyrie->Lrange, this) &&
		!cathedral->enemies->collidesValkyrie(_Valkyrie->Drange, this) &&
		!cathedral->enemies->collidesValkyrie(_Valkyrie->Urange, this)){
		if (cathedral->enemies->alive) {
			if (timeDif <= 5) {
				cathedral->enemies->moveEnemy(1, 0);
			}

			else {
				cathedral->enemies->moveEnemy(-1, 0);
				if (timeDif >= 10) timeDif = 0;
			}
		}
	}
	//this->runAction(Follow::create(_Valkyrie, Rect::ZERO));
	
}

void GameScene::Timer(float dt) {
	timeDif += dt;
	time += dt;
	if (time >= 15) {
		GameScene::_minute++;
		if (GameScene::_minute == 60) {
			GameScene::_minute = 0;
			GameScene::_hour++;
			if (GameScene::_hour == 24) GameScene::_hour = 0; //GameScene::goToGameOverScene(this);
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
			_Valkyrie->right = true;
			break;
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			_Valkyrie->left = true;
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
			_Valkyrie->up = true;
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
			_Valkyrie->down = true;
			break;

		//MENÚ PAUSA
		case EventKeyboard::KeyCode::KEY_SPACE:
			goToPauseScene(this);
			break;

		//ATAQUE BÁSICO
		case EventKeyboard::KeyCode::KEY_Q:
			//CC_CALLBACK_1(MainMenu::goToStartScene, this);
			/*GameScene::_Situation++;
			__String *text = __String::createWithFormat("%d",
				GameScene::_Situation);
			_labelSit->setString(text->getCString());*/
	
			break;
		case EventKeyboard::KeyCode::KEY_D:
			/*if (!cathedral->azureOrb->isTaken) {
				_Valkyrie->itemBag[_Valkyrie->freeSpot] = cathedral->azureOrb;
				_Valkyrie->freeSpot++;
			}*/
			if (!cathedral->azureOrb->isTaken &&
				cathedral->azureOrb->collidesValkyrie(_Valkyrie->Rrange) ||
				cathedral->azureOrb->collidesValkyrie(_Valkyrie->Lrange) ||
				cathedral->azureOrb->collidesValkyrie(_Valkyrie->Drange) ||
				cathedral->azureOrb->collidesValkyrie(_Valkyrie->Urange)) {
				cathedral->azureOrb->takeItem(this);
				GameScene::_healthPoints += 10;
				__String *health = __String::createWithFormat("HP: %.i", GameScene::_healthPoints);
				_labelSit->setString(health->getCString());
			}
			break;
	}
}
void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		_Valkyrie->right = false;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		_Valkyrie->left = false;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		_Valkyrie->up = false;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		_Valkyrie->down = false;
	}
}

void GameScene::setPhysicsWorld(PhysicsWorld *world) {
	mWorld = world;
	mWorld->setGravity(Vec2::ZERO);
}

bool GameScene::onContactBegin(PhysicsContact &contact) {
	return true;
}

/*void GameScene::showItems()
{
	for (int i = 0; i < _Valkyrie->itemBag.size; i++) {
		Item* itemPerI = _Valkyrie->itemBag[i];
		itemPerI->item->setPosition(Point(50 + 80 * i, 50));
		this->addChild(itemPerI, 1);
	}
}*/