#include "NPC.h"

NPC::NPC(cocos2d::Layer * layer, float x, float y)
{
	character = Sprite::create("images/GameScreen/Valquiria.png");
	character->setPosition(x, y);
	width = character->getBoundingBox().size.width;
	height = character->getBoundingBox().size.height;

	posX = character->getPositionX();
	posY = character->getPositionY();
	layer->addChild(character, 2);

}

void NPC::moveCharacterOnCanvas(float x, float y)
{
	character->setPosition(posX + x, posY + y);
	posX = character->getPositionX();
	posY = character->getPositionY();
}

bool NPC::collidesValkyrie(Rect r, cocos2d::Layer* l)
{
	if (r.intersectsRect(character->getBoundingBox()))
	{
		return true;
	}
	else return false;
}