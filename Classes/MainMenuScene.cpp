#include "MainMenuScene.h"
#include "StartScene.h"
#include "CreditsScene.h"
#include "InstructionsScene.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{

	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto background = Sprite::create("images/MainMenuScreen/Background.png");

	background->setPosition(Point((visibleSize.width / 2),
		(visibleSize.height / 2)));
	addChild(background, 0);

	auto menuTitle = MenuItemImage::create("images/MainMenuScreen/Game_Title.png",
		"images/MainMenuScreen/Game_Title.png");

	auto playItem = MenuItemImage::create("images/MainMenuScreen/Play_Button.png",
		"images/MainMenuScreen/Play_Button(Click).png");

	auto menu = Menu::create(menuTitle, playItem, NULL);

	menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);

	_pressedKey = EventKeyboard::KeyCode::KEY_NONE;

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(MainMenu::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(MainMenu::onKeyReleased, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	/*
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/ButtonClick.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("audio/Crash.wav");

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();

	if (audio->isBackgroundMusicPlaying() == false) {
		audio->preloadBackgroundMusic("audio/Music.mp3");
		audio->playBackgroundMusic("audio/Music.mp3", true);
	}
	*/

	addChild(menu, 1);

	return true;
}

void MainMenu::goToStartScene(Ref *pSender) {
	auto scene = StartScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MainMenu::goToCreditsScene(Ref *pSender) {
	auto scene = CreditsScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MainMenu::goToInstructionsScene(Ref *pSender) {
	auto scene = InstructionsScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MainMenu::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
	_pressedKey = keyCode;

	switch (_pressedKey) {
		case EventKeyboard::KeyCode::KEY_Q:
			//CC_CALLBACK_1(MainMenu::goToStartScene, this);
			goToStartScene(this);
			break;
		case EventKeyboard::KeyCode::KEY_W:
			goToCreditsScene(this);
			break;
		case EventKeyboard::KeyCode::KEY_E:
			goToInstructionsScene(this);
			break;
	/*case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_podVector = Vec2(POD_STEP_MOVE, 0);
		_isMoving = true;
		break;
		*/
	}
}
void MainMenu::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event) {
	if (_pressedKey == keyCode) {
		_pressedKey = EventKeyboard::KeyCode::KEY_NONE;
	}
}
