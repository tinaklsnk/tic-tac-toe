#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include <string>
using namespace std;

USING_NS_CC;

#define N 3

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	Size size = Director::getInstance()->getWinSize();
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	director->getOpenGLView()->setFrameSize(600, 600);
	center = Vec2(size.width / 2, size.height / 2);

	auto bg = cocos2d::LayerColor::create(Color4B(255,255,255,255));
	this -> addChild(bg);

	grid = Sprite::create("grid.png");
	grid->setPosition(Vec2(size.width / 2, size.height / 2));
	this->addChild(grid);
	grid->setScale(grid->getContentSize().width/ size.width);

	cross = Sprite::create("cross.png");
	cross->setScale(0.075);
	circle = Sprite::create("circle.png");
	circle->setScale(0.12);

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	/*InitGridRects();
	InitGridPieces();*/

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = true;
		}
	}

	/*EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);*/

	/*//// срабатывает при нажатии
	//listener->onTouchBegan = [](Touch* touch, Event* event) {
	//	// ваш код
	//	return true; // Если вы его приняли
	//};

	//// срабатывает при перемещении касания
	//listener->onTouchMoved = [](Touch* touch, Event* event) {
	//	// ваш код
	//};

	//// срабатывает при отпускании
	//listener->onTouchEnded = [=](Touch* touch, Event* event) {
	//	// ваш код
	//};

	//// Добавляем слушатель
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);*/

	this->scheduleUpdate();

	return true;
}

Sprite* HelloWorld::makeCircle()
{
	auto temp = Sprite::create("circle.png");
	temp->setScale(0.12);
	this->addChild(temp);
	return temp;
}

Sprite* HelloWorld::makeCross()
{
	auto temp = Sprite::create("cross.png");
	temp->setScale(0.075);
	this->addChild(temp);
	return temp;
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	CCLOG(" Key with keycode % d pressed ", keyCode);
	if ((int)keyCode == 77) key1 = true;
	if ((int)keyCode == 78) key2 = true;
	if ((int)keyCode == 79) key3 = true;
	if ((int)keyCode == 80) key4 = true;
	if ((int)keyCode == 81) key5 = true;
	if ((int)keyCode == 82) key6 = true;
	if ((int)keyCode == 83) key7 = true;
	if ((int)keyCode == 84) key8 = true;
	if ((int)keyCode == 85) key9 = true;
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if ((int)keyCode == 77) key1 = false;
	if ((int)keyCode == 78) key2 = false;
	if ((int)keyCode == 79) key3 = false;
	if ((int)keyCode == 80) key4 = false;
	if ((int)keyCode == 81) key5 = false;
	if ((int)keyCode == 82) key6 = false;
	if ((int)keyCode == 83) key7 = false;
	if ((int)keyCode == 84) key8 = false;
	if ((int)keyCode == 85) key9 = false;
}

/*bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
{
	return true;
}
void HelloWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
{

}
void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
{

}
void HelloWorld::onTouchCancelled(Touch* touch, Event* event);
{

}*/

void HelloWorld::update(float dt)
{
	if (key1)
	{
		if (arr[0][0])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x - 90, center.y - 90);
			}
			else 
			{
				auto temp = makeCross();
				temp->setPosition(center.x - 90, center.y - 90);
			}
			arr[0][0] = false;
			turn++;
		}
	}
	if (key2)
	{
		if (arr[0][1])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x, center.y - 90);
			}
			else
			{
				auto temp = makeCross();
				temp->setPosition(center.x, center.y - 90);
			}
			arr[0][1] = false;
			turn++;
		}
	}
	if (key3)
	{
		if (arr[0][2])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x + 90, center.y - 90);
			}
			else
			{
				auto temp = makeCross();
				temp->setPosition(center.x + 90, center.y - 90);
			}
			arr[0][2] = false;
			turn++;
		}
	}
	if (key4)
	{
		if (arr[1][0])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x - 90, center.y );
			}
			else
			{
				auto temp = makeCross();
				temp->setPosition(center.x - 90, center.y);
			}
			arr[1][0] = false;
			turn++;
		}
	}
	if (key5)
	{
		if (arr[1][1])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x , center.y);
			}
			else
			{
				auto temp = makeCross();
				temp->setPosition(center.x, center.y);
			}
			arr[1][1] = false;
			turn++;
		}
	}
	if (key6)
	{
		if (arr[1][2])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x + 90, center.y);
			}
			else
			{
				auto temp = makeCross();
				temp->setPosition(center.x + 90, center.y);
			}
			arr[1][2] = false;
			turn++;
		}
	}
	if (key7)
	{
		if (arr[2][0])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x - 90, center.y+90);
			}
			else
			{
				auto temp = makeCross();
				temp->setPosition(center.x - 90, center.y+90);
			}
			arr[2][0] = false;
			turn++;
		}
	}
	if (key8)
	{
		if (arr[2][1])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x, center.y + 90);
			}
			else
			{
				auto temp = makeCross();
				temp->setPosition(center.x, center.y + 90);
			}
			arr[2][1] = false;
			turn++;
		}
	}
	if (key9)
	{
		if (arr[2][2])
		{
			if (turn % 2 == 1)
			{
				auto temp = makeCircle();
				temp->setPosition(center.x + 90, center.y + 90);
			}
			else
			{
				auto temp = makeCross();
				temp->setPosition(center.x + 90, center.y + 90);
			}
			arr[2][2] = false;
			turn++;
		}
	}

}

