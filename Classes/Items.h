#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "cocos2d.h"
#include "Characters\Valkyrie.h" 

USING_NS_CC;

class Item : public cocos2d::Layer
{
private:


public:
	enum kind;
	kind myKind;
	bool isTaken;

	Item(cocos2d::Layer *layer, float x, float y);
	cocos2d::Sprite *item;
	float width;
	float height;

	float posX;
	float posY;

	void setEffect(kind Kind);

	void moveItem(float x, float y);
	bool collidesValkyrie(Rect r);
	void takeItem(cocos2d::Layer* layer);

};


#endif