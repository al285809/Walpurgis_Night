#ifndef __NPC_H__
#define __NPC_H__

#include "cocos2d.h"

USING_NS_CC;

class NPC : public cocos2d::Layer
{
private:

public:
	NPC(cocos2d::Layer *layer, float x, float y);
	cocos2d::Sprite* character;
	float width;
	float height;

	std::string name;
	int defense;
	float posX;
	float posY;

	void moveCharacterOnCanvas(float x, float y);
	bool collidesValkyrie(Rect r, cocos2d::Layer *layer);
};

#endif