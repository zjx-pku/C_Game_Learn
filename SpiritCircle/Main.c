#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	int marioNum = 0;
	setGameTitle("ÂíÀï°Â×ªÈ¦È¦");
	setGameSize(600, 600);
	createSprite(marioNum,"mario");
	setSpritePosition(marioNum, 0, 0);
	playSpriteAnimate(marioNum, "walk");

	for (int i = 0; i <= 600 - getSpriteHeight(marioNum); i++)
	{
		int pos_x = getSpriteX(marioNum);
		int pos_y = getSpriteY(marioNum);
		pos_y++;
		setSpritePosition(marioNum, pos_x, pos_y);
		pauseGame(10);
	}
	setSpriteFlipX(marioNum, TRUE);
	setSpriteFlipY(marioNum, TRUE);
	for (int i = 0; i <= 600 - getSpriteWidth(marioNum); i++)
	{
		int pos_x = getSpriteX(marioNum);
		int pos_y = getSpriteY(marioNum);
		pos_x++;
		setSpritePosition(marioNum, pos_x, pos_y);
		pauseGame(10);
	}
	setSpriteFlipX(marioNum, FALSE);
	setSpriteFlipY(marioNum, FALSE);
	for (int i = 0; i <= 600 - getSpriteHeight(marioNum); i++)
	{
		int pos_x = getSpriteX(marioNum);
		int pos_y = getSpriteY(marioNum);
		pos_y--;
		setSpritePosition(marioNum, pos_x, pos_y);
		pauseGame(10);
	}
	setSpriteFlipX(marioNum, FALSE);
	setSpriteFlipY(marioNum, FALSE);
	for (int i = 0; i <= 600 - getSpriteWidth(marioNum); i++)
	{
		int pos_x = getSpriteX(marioNum);
		int pos_y = getSpriteY(marioNum);
		pos_x--;
		setSpritePosition(marioNum, pos_x, pos_y);
		pauseGame(10);
	}
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}