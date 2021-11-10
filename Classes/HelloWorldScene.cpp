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
	center = Vec2(size.width / 2, size.height / 2+20);

	auto bg = cocos2d::LayerColor::create(Color4B(255,255,255,255));
	this -> addChild(bg);

	grid = Sprite::create("grid.png");
	grid->setPosition(center);
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


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 0;
		}
	}
	ui::TextField* player1 = ui::TextField::create("player1 name", "Arial", 15);
	player1->setMaxLength(15);
	player1->setMaxLengthEnabled(true);
	player1->setPosition(Vec2(140, 20));
	player1->setColor(Color3B::BLACK);
	ui::TextField* player2 = ui::TextField::create("player2 name", "Arial", 15);
	player2->setMaxLength(15);
	player2->setMaxLengthEnabled(true);
	player2->setPosition(Vec2(350, 20));
	player2->setColor(Color3B::BLACK);
	this->addChild(player1);
	this->addChild(player2);

	/*player1 -> addEventListener([](Ref* sender, ui::TextField::EventType type) 
		{
			auto player1 = dynamic_cast < ui::TextField*> (sender);
			switch (type) {
			case ui::TextField::EventType::ATTACH_WITH_IME:
				CCLOG("displayed keyboard ");
				break;
			case ui::TextField::EventType::DETACH_WITH_IME:
				CCLOG(" dismissed keyboard ");
				break;
			case ui::TextField::EventType::INSERT_TEXT:
				CCLOG("inserted text : % s " , player1-> getString().c_str());
				break;
			case ui::TextField::EventType::DELETE_BACKWARD:
				CCLOG(" deleted backward ");
				break;
			default:
				break;
			}
		});*/

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
		if (arr[0][0]==0)
		{
			GetSprite(0,0)->setPosition(center.x-90, center.y - 90);
		}
	}
	if (key2)
	{
		if (arr[0][1]==0)
		{
			GetSprite(0,1)->setPosition(center.x, center.y - 90);
		}
	}
	if (key3)
	{
		if (arr[0][2]==0)
		{
			GetSprite(0,2)->setPosition(center.x + 90, center.y - 90);
		}
	}
	if (key4)
	{
		if (arr[1][0]==0)
		{
			GetSprite(1,0)->setPosition(center.x - 90, center.y);
		}
	}
	if (key5)
	{
		if (arr[1][1]==0)
		{
				GetSprite(1,1)->setPosition(center.x, center.y);
		}
	}
	if (key6)
	{
		if (arr[1][2]==0)
		{
			GetSprite(1,2)->setPosition(center.x + 90, center.y);
		}
	}
	if (key7)
	{
		if (arr[2][0]==0)
		{
			GetSprite(2,0)->setPosition(center.x - 90, center.y+90);
		}
	}
	if (key8)
	{
		if (arr[2][1]==0)
		{
			GetSprite(2,1)->setPosition(center.x, center.y + 90);
		}
	}
	if (key9)
	{
		if (arr[2][2]==0)
		{
			GetSprite(2,2)->setPosition(center.x + 90, center.y + 90);
		}
	}
	CheckWinner();
}

//circle - 9, cross - 8
Sprite* HelloWorld::GetSprite(int r, int c)
{
	Sprite* temp;
	if (turn % 2 == 1)
	{
		temp = makeCircle();
		arr[r][c] = 9;
	}
	else
	{
		temp = makeCross();
		arr[r][c] = 8;
	}
	turn++;
	return temp;
}

void HelloWorld::CheckWinner()
{
	bool win = false;
	for (int i = 0; i < N; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0]!=0) //horizontal
		{
			if (arr[i][0] == 8)
			{
				MessageBox("Cross", "Winner!");
				win = true;
				break;
			}
			else if (arr[i][0] == 9)
			{
				MessageBox("Circle", "Winner!");
				win = true;
				break;
			}
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != 0) //vertical
		{
			if (arr[0][i] == 8)
			{
				MessageBox("Cross", "Winner!");
				win = true;
				break;
			}
			else if (arr[0][i] == 9)
			{
				MessageBox("Circle", "Winner!");
				win = true;
				break;
			}
		}
		if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1]!=0) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != 0)) //diagonal
		{
			if (arr[1][1] == 8)
			{
				MessageBox("Cross", "Winner!");
				win = true;
				break;
			}
			else if (arr[1][1] == 9)
			{
				MessageBox("Circle", "Winner!");
				win = true;
				break;
			}
		}
	}
	if (win)
	{
		exit(0);
	}
	else if(IsFinished())
	{
		MessageBox("There is no winner", "DRAW");
		exit(0);
	}
}

bool HelloWorld::IsFinished()
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][i] != 0)
			{
				n++;
			}
		}
	}
	if (n == 9)
		return true;
	else
		return false;
}