#include "Characters\Valkyrie.h"
#include "GameScene.h"

USING_NS_CC;

Valkyrie::Valkyrie(cocos2d::Layer *layer, float x, float y) {
	Size visibleSize = Director::getInstance()->getVisibleSize();

	name = "Brunilda";
	//std::string name = CCUserDefault::sharedUserDefault()->getStringForKey("valkyrie");

	//CREACION DEL SPRITE
	valkyrie = Sprite::create("images/GameScreen/Valquiria.png");
	valkyrie->setPosition(x, y);
	width = valkyrie->getBoundingBox().size.width;
	height = valkyrie->getBoundingBox().size.height;
	Lrange = Rect(valkyrie->getPositionX() - width / 2 - 5, valkyrie->getPositionY() - height / 2, 5, width);
	Rrange = Rect(valkyrie->getPositionX() + width / 2, valkyrie->getPositionY() - height / 2, 5, width);
	Drange = Rect(valkyrie->getPositionX() - width / 2, valkyrie->getPositionY() - height / 2 - 5, width, 5);
	Urange = Rect(valkyrie->getPositionX() - width / 2, valkyrie->getPositionY() + width / 2, width, 5);

	//AÑADIMOS FISICAS
	auto body = PhysicsBody::createCircle(width / 2);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	valkyrie->setPhysicsBody(body);	//freeSpot = 0;

	posX = valkyrie->getPositionX();
	posY = valkyrie->getPositionY();

	right = false;
	left = false;
	up = false;
	down = false;

	layer->addChild(valkyrie, 7);
}

void Valkyrie::setStats(std::string name)
{
	if (name == "Brunilda") {
		attack = 4;
		defense = 8;
	}
	if (name == "Gudr") {
		attack = 8;
		defense = 4;
	}
	if (name == "Prudr") {
		attack = 7;
		defense = 5;
	}
}

void Valkyrie::moveValkyrie(int x, int y)
{
	valkyrie->setPosition(Point(valkyrie->getPositionX() + x, valkyrie->getPositionY() + y));
	posX = valkyrie->getPositionX();
	posY = valkyrie->getPositionY();
}

void Valkyrie::Qattack()
{
}

void Valkyrie::Rattack()
{
}
	

	

