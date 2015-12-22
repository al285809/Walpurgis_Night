#include "Data.h"
#include "GameScene.h"
#include "Characters\Valkyrie.h"

void DataClass::setDefaultInformation()
{
	CCUserDefault::sharedUserDefault()->getInstance();
	CCUserDefault::sharedUserDefault()->setIntegerForKey("situation", 0);
	CCUserDefault::sharedUserDefault()->setStringForKey("valkyrie", "Brunilda");
	CCUserDefault::sharedUserDefault()->setIntegerForKey("hour", 23);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("minute", 58);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("HP", 25);
	CCUserDefault::sharedUserDefault()->flush();
}

void DataClass::setCurrentInformation()
{
	CCUserDefault::getInstance();
	CCUserDefault::sharedUserDefault()->setIntegerForKey("situation", GameScene::_Situation);
	CCUserDefault::sharedUserDefault()->setStringForKey("valkyrie", "Brunilda");
	CCUserDefault::sharedUserDefault()->setIntegerForKey("hour", GameScene::_hour);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("minute", GameScene::_minute);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("HP", GameScene::_healthPoints);
	CCUserDefault::sharedUserDefault()->flush();
}

void DataClass::removeData()
{

}
