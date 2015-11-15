#ifndef __GAME_FILE_H__
#define __GAME_FILE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameFile : public cocos2d::Layer
{
private:
	FILE *_dataFile;

public:
	void createFile(int slot);
	void deleteFile(int slot);
	void writeFile(int slot);
	void readFile(int slot);

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameFile);
};

#endif

