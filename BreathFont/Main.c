#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("ºôÎü×ÖÌå");
	setGameSize(600, 600);
	int txtNum = 0;
	int fontSize;
	createText(txtNum, "ÄãºÃ£¡");
	setTextPosition(txtNum, 100, 100);
	while (1)
	{
		for (fontSize = 20; fontSize <= 100; fontSize++)
		{
			setTextFontSize(txtNum, fontSize);
			pauseGame(100);
		}
		for (fontSize = 100; fontSize >= 20; fontSize--)
		{
			setTextFontSize(txtNum, fontSize);
			pauseGame(100);
		}
	}
	
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}