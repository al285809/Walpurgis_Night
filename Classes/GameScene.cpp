#include "GameScene.h"
#include "GameOverScene.h"
#include "PauseScene.h"
#include "StartScene.h"
#include <string>

USING_NS_CC;

int GameScene::_Situation;
std::string GameScene::_valkyrie;
std::string GameScene::_hour;

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

	Size _visibleSize = Director::getInstance()->getVisibleSize();

	GameScene::_Situation = CCUserDefault::sharedUserDefault()->getIntegerForKey("situation");
	GameScene::_valkyrie = CCUserDefault::sharedUserDefault()->getStringForKey("valkyrie");
	GameScene::_hour = CCUserDefault::sharedUserDefault()->getStringForKey("hour");
	seconds = 0;
	
	//////////////////////////////
	// 2. create background
	auto background = Sprite::create("images/GameScreen/portadaCaca.png");

	background->setPosition(Point((_visibleSize.width / 2),
		(_visibleSize.height / 2)));
	addChild(background, 0);

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

	_labelHour = Label::createWithTTF(GameScene::_hour, "fonts/MArker Felt.ttf", 24);

	_labelHour->setPosition(Vec2(_visibleSize.width / 2, 50));
	addChild(_labelHour, 3);

	return true;
}

void GameScene::moveScene() {

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

void GameScene::setCurrentInformation() {
	CCUserDefault::getInstance();
	CCUserDefault::sharedUserDefault()->setIntegerForKey("situation", GameScene::_Situation);
	CCUserDefault::sharedUserDefault()->setStringForKey("valkyrie", GameScene::_valkyrie);
	CCUserDefault::sharedUserDefault()->setStringForKey("hour", GameScene::_hour);
	CCUserDefault::sharedUserDefault()->flush();
}

void GameScene::setTimer() {

}
