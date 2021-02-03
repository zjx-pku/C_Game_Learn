#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{	/*mario的初始位置*/
	int posX = 0;							//mario的初始x坐标
	int posY = 0;							//mario的初始y坐标
	
	/*mario的规格*/
	int spriteWidth = 31;					//mario宽度
	int spriteHeight = 47;					//mario高度

	/*各种元素的代码*/
	int marioNum = 0;						//mario精灵的代码
	int gameStartBankgroundNum = 0;			//游戏背景图片代码
	int scoreTextNum = 0;					//显示实时分数的文字的代码
	int gameOverTextNum = 1;				//显示游戏结束的文字的代码

	/*游戏框设置*/
	int gameWidth = 338;					//游戏框的宽度
	int gameHeight = 600;					//游戏框的长度
	setGameTitle("马里奥吃金币");				//游戏框的名称
	setGameSize(gameWidth, gameHeight);		//设置游戏框的规格

	/*生成mario精灵并播放站立的动画*/
	createSprite(marioNum, "mario");		//生成mario精灵
	playSpriteAnimate(marioNum, "idle");	//尚未运动，设置站立的动画
	setSpritePosition(marioNum, 0, 0);		//设置mario的初始位置

	/*显示游戏背景图*/
	createImage(gameStartBankgroundNum, "大片草地.png");
	showImage(gameStartBankgroundNum);

	/*显示金币元素*/
	int coinNums[] = { 1,2,3,4,5,6,7,8 };					//金币编号数组
	int coinXs[] = { 110,210,130,340,250,160,170,280 };		//金币x坐标数组
	int coinYs[] = { 88,117,18,181,200,204,301,350 };		//金币y坐标数组
	int coinCount = sizeof(coinXs) / sizeof(coinXs[0]);     //金币数量
	int i;
	for (i = 0; i < coinCount; i++)							//迭代展示每个金币及其动画
	{
		int coinNum = coinNums[i];
		createSprite(coinNum, "coin");
		playSpriteAnimate(coinNum, "rotate");
		setSpritePosition(coinNum, coinXs[i], coinYs[i]);
	}

	/*显示炸弹元素*/
	int bombNums[] = { 11,12,13,14,15 };					//炸弹编号数组
	int bombXs[] = { 299,100,118,181,50 };					//炸弹x坐标数组
	int bombYs[] = { 110,200,155,340,299 };					//炸弹y坐标数组
	int bombCount = sizeof(bombNums) / sizeof(bombNums[0]);	//炸弹数量
	int j;
	for (j = 0; j < bombCount; j++)							//迭代展示每个炸弹其动画
	{
		int bombNum = bombNums[j];
		createSprite(bombNum, "bomb");
		playSpriteAnimate(bombNum, "laser");
		setSpritePosition(bombNum, bombXs[j], bombYs[j]);
	}

	/*文本元素*/
	createText(scoreTextNum, "");							//创建显示分数的文本对象（初始为空串）
	setTextPosition(scoreTextNum, 0, 570);					//设置显示分数的文本的位置
	setTextColor(scoreTextNum, 1, 0, 0);					//设置显示分数的文本的位置
	setTextFontSize(scoreTextNum, 30);						//设置显示分数的文本的字体大小

	createText(gameOverTextNum, "");						//创建显示游戏结束的文本对象（初始为空串）
	showText(gameOverTextNum);

	int ateCoinNum = 0;					//初始化已经吃掉的金币数量
	char message[1000] = "";			//初始化显示分数的文本对象

	while (1)					
	{
		/*获取按键（上下左右）并根据按键移动mario精灵*/
		int a = getPressedKeyCode();						//获取按键
		switch (a)
		{
		case RP_KEY_LEFT:									//按键为左
			posX -= 5;										//x坐标减少5
			if (posX < 0)									//是否越过左界
				posX = 0;
			setSpritePosition(marioNum, posX, posY);		//设置mario位置
			setSpriteFlipX(marioNum, FALSE);				//脸的朝向不变
			playSpriteAnimate(marioNum, "walk");			//播放走路的动画
			break;
		case RP_KEY_RIGHT:									//按键为右
			posX += 5;										//x坐标加5
			if (posX > gameWidth - spriteWidth)				//判断是否越过右界
				posX = gameWidth - spriteWidth;
			setSpritePosition(marioNum, posX, posY);		//设置mario的位置
			setSpriteFlipX(marioNum, TRUE);					//脸的朝向反向
			playSpriteAnimate(marioNum, "walk");			//播放走路动画
			break;
		case RP_KEY_UP:										//按键为上
			posY += 5;										//y坐标加5
			if (posY > gameHeight - spriteHeight)			//判断是否越过上界
				posY = gameHeight - spriteHeight;
			setSpritePosition(marioNum, posX, posY);		//设置mario的位置
			playSpriteAnimate(marioNum, "walk");			//播放走路动画
			break;
		case RP_KEY_DOWN:									//按键为下
			posY -= 5;										//y坐标减少5
			if (posY < 0)									//判断是否越过下界
				posY = 0;
			setSpritePosition(marioNum, posX, posY);		//设置mario位置
			playSpriteAnimate(marioNum, "walk");			//播放走路动画
			break;
		default:											//没有按键
			playSpriteAnimate(marioNum, "idle");			//播放静止动画		
			break;
		}

		/*判断是否碰到金币*/
		for (i = 0; i < coinCount; i++)
		{
			/*碰到金币后相应金币消失，吃到的金币数加一*/
			if (isSpriteVisible(i + 1) && ((posX - coinXs[i])*(posX - coinXs[i]) + (posY - coinYs[i])*(posY - coinYs[i])) < 100)
			{
				hideSprite(i + 1);
				ateCoinNum++;
			}

			/*设置并展示相应的分数信息*/
			if (ateCoinNum <= 1)
			{
				sprintf(message, "You have eat %d coin", ateCoinNum);
			}
			else
			{
				sprintf(message, "You have eat %d coins", ateCoinNum);
			}
			setText(scoreTextNum, message);

		}

		/*判断是否碰到炸弹*/
		for (j = 0; j < bombCount; j++)
		{
			/*碰到炸弹后播放fire动画，显示最终得分情况和GameOver的信息，退出游戏*/
			if (((posX - bombXs[j])*(posX - bombXs[j]) + (posY - bombYs[j])*(posY - bombYs[j])) < 100)
			{
				playSpriteAnimate(bombNums[j], "fire");

				/*显示最终得分情况*/
				setText(scoreTextNum, message);
				setTextPosition(scoreTextNum, 0, 270);
				setTextFontSize(scoreTextNum, 30);
				setTextColor(scoreTextNum, 0, 0, 1);

				/*显示GameOver*/
				setText(gameOverTextNum, "GAME OVER!");
				setTextPosition(gameOverTextNum, 70, 310);
				setTextFontSize(gameOverTextNum, 35);
				setTextColor(gameOverTextNum, 1, 0, 0);

				/*暂停游戏并退出*/
				pauseGame(5000);
				exit(0);
			}
		}
		pauseGame(50);
	}
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}