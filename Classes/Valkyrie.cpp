#include "Valkyrie.h"

USING_NS_CC;

Valkyrie::Valkyrie(cocos2d::Layer *layer) {
	/*Size visibleSize = Director::getInstance()->getVisibleSize();

	Vname = "Brunilda";
	//std::string Vname = CCUserDefault::sharedUserDefault()->getStringForKey("valkyrie");
	if (Vname == "Brunilda") {
		attack = 4;
		defense = 8;
	}
	if (Vname == "Gudr") {
		attack = 8;
		defense = 4;
	}
	if (Vname == "Prudr") {
		attack = 7;
		defense = 5;
	}**/

	valkyrie = Sprite::create("images/GameScreen/Valquiria.png");
	valkyrie->setScale(4);
	//valkyrie->setPosition(Point((visibleSize.width / 2),
	//	(visibleSize.height / 2)));

	//posX = valkyrie->getPositionX();
	//posY = valkyrie->getPositionY();

	layer->addChild(valkyrie, 1);
}

void Valkyrie::moveValkyrie(int x, int y)
{
	//valkyrie->setPosition(Point(getPositionX() + x, getPositionY() + y));
}
	

	

