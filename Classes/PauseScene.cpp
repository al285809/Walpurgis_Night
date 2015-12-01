#include "PauseScene.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Data.h"

USING_NS_CC;

Scene* PauseScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PauseScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PauseScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create("images/PauseScreen/PauseImage.jpg");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));
	addChild(background, 0);

	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(PauseScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(PauseScene::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void PauseScene::resumeGameScene(Ref *pSender) {
	Director::getInstance()->popScene();
}
void PauseScene::goToMainMenu(Ref *pSender) {
	auto scene = MainMenu::createScene();

	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}
void PauseScene::retryGameScene(Ref *pSender) {
	auto scene = GameScene::createScene();

	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}

void PauseScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
	case EventKeyboard::KeyCode::KEY_Q:
		DataClass::setCurrentInformation();
		goToMainMenu(this);
		break;
	case EventKeyboard::KeyCode::KEY_R:
		resumeGameScene(this);
		break;
		/*case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		_podVector = Vec2(-POD_STEP_MOVE, 0);
		_isMoving = true;
		break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_podVector = Vec2(POD_STEP_MOVE, 0);
		_isMoving = true;
		break;
		*/
	}
}
void PauseScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}
