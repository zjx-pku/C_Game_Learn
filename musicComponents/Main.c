#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("微信打飞机");
	setGameSize(338, 600);
	playSound("超级玛丽.mp3",TRUE); //播放音乐，通过名称进行索引，布尔值代表是否重复播放（后台音乐，并不会阻断函数运行）
									//并列的playSound并行播放
	pauseGame(10000);
	closeSound("超级玛丽.mp3");		//关闭播放的音乐

	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}