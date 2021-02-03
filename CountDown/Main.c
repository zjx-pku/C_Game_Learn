#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("µ¹¼ÆÊ±");
	setGameSize(600, 600);
	int time;
	int txtNum = 0;
	createText(txtNum, "200");
	setTextPosition(txtNum,270, 300);
	setTextFontSize(txtNum, 50);

	for (time = 200; time >= 0; time--)
	{
		char stime[5] = { 0 };
		sprintf(stime, "%d", time);
		setText(txtNum, stime);
		pauseGame(1000);
	}
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}