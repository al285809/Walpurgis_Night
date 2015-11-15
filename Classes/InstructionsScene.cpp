#include "InstructionsScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* InstructionsScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = InstructionsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool InstructionsScene::init()
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

	listener->onKeyPressed = CC_CALLBACK_2(InstructionsScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(InstructionsScene::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void InstructionsScene::goToMainMenu(Ref *pSender) {
	auto scene = MainMenu::createScene();
	Director::getInstance()->replaceScene(scene);
}

void InstructionsScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
		case EventKeyboard::KeyCode::KEY_R:
			goToMainMenu(this);
			break;
	}
}
void InstructionsScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}