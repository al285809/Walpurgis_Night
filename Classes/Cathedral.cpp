#include "Cathedral.h"

USING_NS_CC;

Cathedral::Cathedral(cocos2d::Layer * layer, float x, float y)
{
	floor = Sprite::create("images/GameScreen/suelo2.png");
	floor->setPosition(x, y);

	light = Sprite::create("images/GameScreen/luznaranja.png");
	light->setPosition(x, y);
	light->setOpacity(150);

	crystalWall = Sprite::create("images/GameScreen/vidrieracatedral.png");
	crystalWall->setPosition(x, 1250 + y);

	Lwall = Sprite::create("images/GameScreen/paredIZQcatedral.png");
	Lwall->setPosition(x - 448 ,y + 190);

	Rwall = Sprite::create("images/GameScreen/paredDERcatedral.png");
	Rwall->setPosition(x + 448, y + 190);

	RIwall = Sprite::create("images/GameScreen/paredDERINFcatedral.png");
	RIwall->setPosition(x - 482 + RIwall->getBoundingBox().size.width/2, y - 611.5);

	RDwall = Sprite::create("images/GameScreen/paredDERINFcatedral.png");
	RDwall->setPosition(x + 482 - RIwall->getBoundingBox().size.width/2, y - 611.5);

	exit = Rect(x- 200, y- 700, 120, 20);

	posX = floor->getPositionX();
	posY = floor->getPositionY();
	lightposX = light->getPositionX();
	lightposY = light->getPositionY();
	crystalposX = crystalWall->getPositionX();
	crystalposY = crystalWall->getPositionY();

	layer->addChild(floor, 0);
	layer->addChild(light, 9);
	layer->addChild(crystalWall, 3);
	layer->addChild(Lwall, 3);
	layer->addChild(Rwall, 3);
	layer->addChild(RDwall, 3);
	layer->addChild(RIwall, 3);

	enemies = new Enemies(layer, x - 200, y - 200);
	character = new NPC(layer, x, y - 500);
	azureOrb = new Item(layer, x - 100, y - 100);
}

void Cathedral::moveSpace(float x, float y)
{
	floor->setPosition(posX + x, posY + y);
	posX = floor->getPositionX();
	posY = floor->getPositionY();

	light->setPosition(posX + x, posY + y);
	lightposX = light->getPositionX();
	lightposY = light->getPositionY();

	crystalWall->setPosition(crystalposX + x, crystalposY + y);
	crystalposX = crystalWall->getPositionX();
	crystalposY = crystalWall->getPositionY();

	Lwall->setPosition(Lwall->getPositionX() + x, Lwall->getPositionY() + y);
	Rwall->setPosition(Rwall->getPositionX() + x, Rwall->getPositionY() + y);
	RIwall->setPosition(RIwall->getPositionX() + x, RIwall->getPositionY() + y);
	RDwall->setPosition(RDwall->getPositionX() + x, RDwall->getPositionY() + y);

	if (! azureOrb->isTaken) azureOrb->moveItem(x, y);
	if(enemies->alive) enemies->moveEnemyOnCanvas(x, y);
	character->moveCharacterOnCanvas(x, y);
}

bool Cathedral::collidesValkyrie(Rect r)
{
	if (r.intersectsRect(crystalWall->getBoundingBox()) ||
		r.intersectsRect(Lwall->getBoundingBox()) ||
		r.intersectsRect(Rwall->getBoundingBox()) ||
		r.intersectsRect(RIwall->getBoundingBox()) || 
		r.intersectsRect(RDwall->getBoundingBox()) ||
		r.intersectsRect(enemies->enemy->getBoundingBox()) ||
		(!azureOrb->isTaken && r.intersectsRect(azureOrb->item->getBoundingBox())) ||
		r.intersectsRect(character->character->getBoundingBox())) return true;
	else return false;
}
