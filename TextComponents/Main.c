#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("TextComponents");		//设置游戏标题
	setGameSize(192, 108);		//设置游戏框大小，先横后竖
	createText(0, "PKU");		//创建文本对象，对应索引为0
	setTextPosition(0, 50, 50);	//设置文本位置，第一个元素为文本对象的索引，第二三个元素为位置x,y
	setTextFontSize(0, 50);		//设置字体大小，第一个元素为文本对象的索引，第二个对象为字体大小
	setText(0, "THU");			//修改文本对象的内容
	hideText(0);				//隐藏文本对象
	showText(0);				//显示文本对象
	setTextColor(0, 1.0f, 0.0f, 0.0f);		//设置文本对象的颜色(r,g,b)，取值[0,1]
	int x = getTextX(0);					//返回文本对象的x坐标
	int y = getTextY(0);					//返回文本对象的y坐标
	int isTextVisable = isTextVisible(0);	//返回文本对象是否可见
	pauseGame(10000);						//暂停1000毫秒
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}