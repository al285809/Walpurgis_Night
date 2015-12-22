#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "Data.h"

USING_NS_CC;

Scene* GameOver::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOver::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create("images/GameOverScreen/GameOverImg.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));
	addChild(background, 0);


	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(GameOver::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameOver::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void GameOver::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event)
{
	_pressedKey = keyCode;
	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_Q:
		GameOver::goToGameScene(this);
		break;
	case EventKeyboard::KeyCode::KEY_R:
		GameOver::goToMainMenu(this);
		break;
	}
}

void GameOver::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}

void GameOver::goToMainMenu(Ref *pSender) {
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void GameOver::goToGameScene(Ref *pSender) {
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
