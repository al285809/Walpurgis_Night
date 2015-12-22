#include "Items.h"
#include "Characters\Valkyrie.h"

USING_NS_CC;

enum kind {GULESORB, AZUREORB = 1, SABLEORB, SINOPLEORB, VOIDLAMP, REVERSECLOCK};

Item::Item(cocos2d::Layer * layer, float x, float y)
{
	//myKind = k;

	item = Sprite::create("images/GameScreen/AzureOrb.png");
	item->setPosition(x, y);
	width = item->getBoundingBox().size.width;
	height = item->getBoundingBox().size.height;

	posX = item->getPositionX();
	posY = item->getPositionY();

	//AÑADIMOS FISICAS
	auto body = PhysicsBody::createCircle(item->getBoundingBox().size.width / 2);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	item->setPhysicsBody(body);

	isTaken = false;
	layer->addChild(item, 2);
}

void Item::moveItem(float x, float y)
{
	item->setPosition(posX + x, posY + y);
	posX = item->getPositionX();
	posY = item->getPositionY();
}

bool Item::collidesValkyrie(Rect r)
{
	if (! isTaken && r.intersectsRect(item->getBoundingBox()))
	{
		return true;
	}
	else return false;
}

void Item::takeItem(cocos2d::Layer* layer)
{
	isTaken = true;
	layer->removeChild(item);
}

