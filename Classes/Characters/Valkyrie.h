#ifndef __VALKYRIE_H__
#define __VALKYRIE_H__

#include "cocos2d.h"

USING_NS_CC;

class Valkyrie : public cocos2d::Layer
{
private:
	

public:
    Valkyrie(cocos2d::Layer *layer, float x, float y);

	cocos2d::Sprite *valkyrie;
	Rect Rrange;
	Rect Lrange;
	Rect Urange;
	Rect Drange;
	float width;
	float height;

	std::string name;
	int attack;
	int defense;
	float posX;
	float posY;

	bool right;
	bool left;
	bool up;
	bool down;

	
	//int freeSpot;

	void setStats(std::string name);

	void moveValkyrie(int x, int y);
	void Qattack();
	void Rattack();
};

#endif

















