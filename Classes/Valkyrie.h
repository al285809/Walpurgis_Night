#ifndef __VALKYRIE_H__
#define __VALKYRIE_H__

#include "cocos2d.h"

USING_NS_CC;

class Valkyrie : public cocos2d::Layer
{
private:
	cocos2d::Sprite* valkyrie;

public:
	Valkyrie(cocos2d::Layer *layer);

	std::string Vname;
	int attack;
	int defense;
	float posX;
	float posY;

	static void moveValkyrie(int x, int y);
};

#endif