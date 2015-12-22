#ifndef __CATHEDRAL_H__
#define __CATHEDRAL_H__

#include "cocos2d.h"
#include "Items.h"
#include "Characters\Enemies.h"
#include "Characters\NPC.h"

USING_NS_CC;

class Cathedral : public cocos2d::Layer
{
private:


public:
	Cathedral(cocos2d::Layer *layer, float x, float y);

	cocos2d::Sprite *floor;
	cocos2d::Sprite *crystalWall;
	cocos2d::Sprite *Lwall;
	cocos2d::Sprite *Rwall;
	cocos2d::Sprite *RIwall;
	cocos2d::Sprite *RDwall;
	cocos2d::Sprite *light;


	cocos2d::Rect exit;

	float posX;
	float posY;

	float lightposX;
	float lightposY;

	float crystalposX;
	float crystalposY;

	Enemies* enemies;
	NPC* character;
	Item* azureOrb;

	void moveSpace(float x, float y);
	bool collidesValkyrie(Rect r);
};

#endif