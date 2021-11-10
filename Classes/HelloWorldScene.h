/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(HelloWorld);

    cocos2d::Sprite* circle;
    cocos2d::Sprite* cross;

    cocos2d::Sprite* makeCircle();
    cocos2d::Sprite* makeCross();

    void update(float dt);

    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    bool key1 = false;
    bool key2 = false;
    bool key3 = false;
    bool key4 = false;
    bool key5 = false;
    bool key6 = false;
    bool key7 = false;
    bool key8 = false;
    bool key9 = false;

    bool arr[3][3];

    cocos2d::Vec2 center;

    //bool  onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    //void  onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    //void  onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    //void  onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

   /* void InitGridRects();
    void InitGridPieces();

    void CheckAndPLacePiece(cocos2d::Touch* touch);
    void CheckWin(int x, int y);
    void Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3);*/

    cocos2d::Sprite* grid;
    cocos2d::Rect gridSpaces[3][3];
    cocos2d::Sprite* gridpieces[3][3];
    int gridArray[3][3];
    int turn=0;
    int gameState;
};

#endif // __HELLOWORLD_SCENE_H__
