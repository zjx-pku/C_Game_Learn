#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void motion(int speedX,int speedY,
	int spritNum,int gameWidth, int gameHeight,int imageWidth, int imageHeight) //定义小球的运动
{
	int curPosX = getSpriteX(spritNum);   //当前小球的x坐标
	int curPosY = getSpriteY(spritNum);	  //当前小球的y坐标
	int posX = curPosX +  speedX;		  //1秒后小球的x坐标
	int posY = curPosY +  speedY;		  //1秒后小球的y坐标

	if (posY > gameHeight - imageHeight)  //如果超出上界
		posY = gameHeight - imageHeight;

	if (posY < 0)						  //如果超出下界
		posY = 0;

	if (posX > gameWidth - imageWidth)  //如果超出右界
		posX = gameWidth - imageWidth;

	if (posX < 0)						  //如果超出左界
		posX = 0;
	setSpritePosition(spritNum, posX, posY);//更新小球位置
}

void gameMain(void)
{
	int ballNum = 0;
	int gameHeigth = 600;
	int gameWidth = 600;
	int initPosX = 0;
	int initPosY = 300;
	int speedX = 10;
	int speedY = 10;

	setGameTitle("碰撞小球");
	setGameSize(gameWidth,gameHeigth);
	createSprite(ballNum, "ball1");
	playSpriteAnimate(ballNum, "rotate");
	setSpritePosition(ballNum, initPosX, initPosY);

	int spritHeight = 24;
	int spritWidth = 24;//估计是引擎有bug，获取得到的spritWidth和spritHeisght都是0，因此在这里直接赋值

	while (1)
	{
		int posX = getSpriteX(ballNum);
		int posY = getSpriteY(ballNum);

		if (posY == gameHeigth - spritHeight || posY == 0) //如果碰到上界或下界，y方向的速度反向
			speedY = -speedY;

		if (posX == gameWidth - spritWidth || posX == 0) //如果碰到左界或右界，x方向的速度反向
			speedX = -speedX;

		motion(speedX, speedY, ballNum, gameWidth, gameHeigth, spritWidth,spritHeight); //更新小球位置
		
		pauseGame(100);										//相当于时间流逝
	}

}

int main(void)
{
	rpInit(gameMain);
	return 0;
}