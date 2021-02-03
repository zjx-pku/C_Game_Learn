#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{

	if (confirm("你是好人吗？"))								//询问函数，如果用户点击“是”，则返回值为1；否则返回值为0
	{
		alert("你好！欢迎来到C语言的世界。我的名字是%s", "张建学");	//显示消息框，是个阻塞函数，只有点击确定后程序才会向下运行
	}
	else
	{
		alert("你是个大坏蛋，滚粗！");
	}
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}