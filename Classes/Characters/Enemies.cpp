#include "Characters\Enemies.h"
#include "Characters\Valkyrie.h"

USING_NS_CC;
	
Enemies::Enemies(cocos2d::Layer * layer, float x, float y)
{
	enemy = Sprite::create("images/GameScreen/Valquiria.png");
	enemy->setPosition(x, y);
	width = enemy->getBoundingBox().size.width;
	height = enemy->getBoundingBox().size.height;

	posX = enemy->getPositionX();
	posY = enemy->getPositionY();
	alive = true;

	/*auto body = PhysicsBody::createCircle(width / 2);
	body->setContactTestBitmask(true);
	body->setDynamic(true);
	enemy->setPhysicsBody(body);*/
	layer->addChild(enemy, 7);
}

void Enemies::moveEnemyOnCanvas(float x, float y)
{
	enemy->setPosition(posX + x, posY + y);
	posX = enemy->getPositionX();
	posY = enemy->getPositionY();
}

void Enemies::moveEnemy(float x, float y)
{
	enemy->setPosition(posX + x, posY + y);
	posX = enemy->getPositionX();
	posY = enemy->getPositionY();
}

bool Enemies::collidesValkyrie(Rect r, cocos2d::Layer* l)
{
	if (r.intersectsRect(enemy->getBoundingBox()))
	{
		return true;
	}
	else return false;
}
