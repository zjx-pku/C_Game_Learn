#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("AnimationComponents");
	setGameSize(338, 600);
	createSprite(0, "girl");		//创建精灵对象，文件在Sprites目录下，精灵名称要与文件保持一致
	playSpriteAnimate(0, "dance1");	//播放精灵动画，动作名称要与文件保持一致。默认一直播放动画
	setSpriteRepeatPlay(0, FALSE);	//设置是否重复播放动画，false表示只播放一次
	setSpritePosition(0, 100, 20);	//设置动画的左下角位置（图片为矩形）
	setSpriteFlipX(0, TRUE);		//动画是否在x轴方向上反转（针对原始图片来说）
	setSpriteFlipY(0, TRUE);		//动画是否在y轴方向上反转（针对原始图片来说）
	int x = getSpriteX(0);			//动画左下角点的x坐标
	int y = getSpriteY(0);			//动画左下角点的y坐标
	int width = getSpriteWidth(0);	//图片宽度
	int height = getSpriteHeight(0);//图片高度
	hideSprite(0);					//隐藏图片
	showSprite(0);					//显示图片
	int isVisable = isSpriteVisible(0);//图片是否可见

	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}