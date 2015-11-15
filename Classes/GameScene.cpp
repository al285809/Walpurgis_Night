#include "GameScene.h"
#include "GameOverScene.h"
#include "PauseScene.h"

USING_NS_CC;

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

	Size visibleSize = Director::getInstance()->getVisibleSize();

	
	//////////////////////////////
	// 2. create background
	auto background = Sprite::create("images/GameScreen/portadaCaca.png");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));
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
	//_sceneId = Situation;

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
	
	}
}
void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}
