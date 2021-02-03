#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("PictureComponents");
	setGameSize(1920, 1080);
	createImage(0, "wallhaven-vmpwrl.png");		//创建图片元素，图片放image文件夹内，然后重新生成解决方案。只能加载PNG格式，使用图片名进行加载
	setImagePosition(0, 10, 1);					//修改图片左下角点的位置
	setImagePosition(0, 0, 0);
	setImageSource(0, "wallhaven-ox9ry7.png");	//修改图片源
	hideImage(0);								//隐藏图片
	showImage(0);								//显示图片
	int x = getImageX(0);						//获得图片左下角点的位置x坐标
	int y = getImageY(0);						//获得图片左下角点的位置y坐标
	int width = getImageWidth(0);				//获得图片宽度
	int height = getImageHeight(0);				//获得图片高度
	int isVisable = isImageVisible(0);			//返回图片是否可见
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}