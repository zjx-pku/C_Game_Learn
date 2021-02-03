#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	int marioNum = 0;
	setGameTitle("ÂíÀï°Â");
	setGameSize(600, 600);
	createSprite(marioNum, "mario");
	setSpritePosition(marioNum, 300, 300);
	playSpriteAnimate(marioNum, "walk");
	for (int i = 0; i <= 300; i++)
	{
		int pos_x = getSpriteX(marioNum);
		int pos_y = getSpriteY(marioNum);
		pos_x--;
		setSpritePosition(marioNum, pos_x, pos_y);
		pauseGame(100);

	}
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}