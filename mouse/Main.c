#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("微信打飞机");
	setGameSize(600, 600);
	createImage(0, "mouse.png");		//创建图片对象（瞄准镜）
	hideMouseCursor();					//隐藏鼠标指针
	while (1)
	{
		int x = getMousePositionX();	//实时获取鼠标x坐标
		int y = getMousePositionY();	//实时获取鼠标y坐标
		setImagePosition(0, x - getImageWidth(0) / 2, y - getImageHeight(0) / 2); //根据鼠标位置设置图片位置
	}
	int isDown = isMouseLeftButtonDown();//判断鼠标左键是否点击
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}