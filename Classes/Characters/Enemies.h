#ifndef __ENEMIES_H__
#define __ENEMIES_H__

#include "cocos2d.h"
#include "Characters\Valkyrie.h"

USING_NS_CC;

class Enemies : public cocos2d::Layer
{
private:

public:
	Enemies(cocos2d::Layer *layer, float x, float y);
	cocos2d::Sprite* enemy;
	float width;
	float height;

	std::string name;
	int attack;
	int defense;
	float posX;
	float posY;
	bool alive;

	void moveEnemyOnCanvas(float x, float y);
	void moveEnemy(float x, float y);
	bool collidesValkyrie(Rect r, cocos2d::Layer *layer);
};

#endif