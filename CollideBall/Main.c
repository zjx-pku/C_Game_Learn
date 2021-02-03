#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void motion(int speedX,int speedY,
	int spritNum,int gameWidth, int gameHeight,int imageWidth, int imageHeight) //����С����˶�
{
	int curPosX = getSpriteX(spritNum);   //��ǰС���x����
	int curPosY = getSpriteY(spritNum);	  //��ǰС���y����
	int posX = curPosX +  speedX;		  //1���С���x����
	int posY = curPosY +  speedY;		  //1���С���y����

	if (posY > gameHeight - imageHeight)  //��������Ͻ�
		posY = gameHeight - imageHeight;

	if (posY < 0)						  //��������½�
		posY = 0;

	if (posX > gameWidth - imageWidth)  //��������ҽ�
		posX = gameWidth - imageWidth;

	if (posX < 0)						  //����������
		posX = 0;
	setSpritePosition(spritNum, posX, posY);//����С��λ��
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

	setGameTitle("��ײС��");
	setGameSize(gameWidth,gameHeigth);
	createSprite(ballNum, "ball1");
	playSpriteAnimate(ballNum, "rotate");
	setSpritePosition(ballNum, initPosX, initPosY);

	int spritHeight = 24;
	int spritWidth = 24;//������������bug����ȡ�õ���spritWidth��spritHeisght����0�����������ֱ�Ӹ�ֵ

	while (1)
	{
		int posX = getSpriteX(ballNum);
		int posY = getSpriteY(ballNum);

		if (posY == gameHeigth - spritHeight || posY == 0) //��������Ͻ���½磬y������ٶȷ���
			speedY = -speedY;

		if (posX == gameWidth - spritWidth || posX == 0) //������������ҽ磬x������ٶȷ���
			speedX = -speedX;

		motion(speedX, speedY, ballNum, gameWidth, gameHeigth, spritWidth,spritHeight); //����С��λ��
		
		pauseGame(100);										//�൱��ʱ������
	}

}

int main(void)
{
	rpInit(gameMain);
	return 0;
}