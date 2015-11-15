#include "CreditsScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* CreditsScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CreditsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool CreditsScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(CreditsScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(CreditsScene::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void CreditsScene::goToMainMenu(Ref *pSender) {
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}


void CreditsScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
		case EventKeyboard::KeyCode::KEY_R:
			goToMainMenu(this);
			break;
	}
}
void CreditsScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}