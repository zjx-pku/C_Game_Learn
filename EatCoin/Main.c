#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{	/*mario�ĳ�ʼλ��*/
	int posX = 0;							//mario�ĳ�ʼx����
	int posY = 0;							//mario�ĳ�ʼy����
	
	/*mario�Ĺ��*/
	int spriteWidth = 31;					//mario���
	int spriteHeight = 47;					//mario�߶�

	/*����Ԫ�صĴ���*/
	int marioNum = 0;						//mario����Ĵ���
	int gameStartBankgroundNum = 0;			//��Ϸ����ͼƬ����
	int scoreTextNum = 0;					//��ʾʵʱ���������ֵĴ���
	int gameOverTextNum = 1;				//��ʾ��Ϸ���������ֵĴ���

	/*��Ϸ������*/
	int gameWidth = 338;					//��Ϸ��Ŀ��
	int gameHeight = 600;					//��Ϸ��ĳ���
	setGameTitle("����³Խ��");				//��Ϸ�������
	setGameSize(gameWidth, gameHeight);		//������Ϸ��Ĺ��

	/*����mario���鲢����վ���Ķ���*/
	createSprite(marioNum, "mario");		//����mario����
	playSpriteAnimate(marioNum, "idle");	//��δ�˶�������վ���Ķ���
	setSpritePosition(marioNum, 0, 0);		//����mario�ĳ�ʼλ��

	/*��ʾ��Ϸ����ͼ*/
	createImage(gameStartBankgroundNum, "��Ƭ�ݵ�.png");
	showImage(gameStartBankgroundNum);

	/*��ʾ���Ԫ��*/
	int coinNums[] = { 1,2,3,4,5,6,7,8 };					//��ұ������
	int coinXs[] = { 110,210,130,340,250,160,170,280 };		//���x��������
	int coinYs[] = { 88,117,18,181,200,204,301,350 };		//���y��������
	int coinCount = sizeof(coinXs) / sizeof(coinXs[0]);     //�������
	int i;
	for (i = 0; i < coinCount; i++)							//����չʾÿ����Ҽ��䶯��
	{
		int coinNum = coinNums[i];
		createSprite(coinNum, "coin");
		playSpriteAnimate(coinNum, "rotate");
		setSpritePosition(coinNum, coinXs[i], coinYs[i]);
	}

	/*��ʾը��Ԫ��*/
	int bombNums[] = { 11,12,13,14,15 };					//ը���������
	int bombXs[] = { 299,100,118,181,50 };					//ը��x��������
	int bombYs[] = { 110,200,155,340,299 };					//ը��y��������
	int bombCount = sizeof(bombNums) / sizeof(bombNums[0]);	//ը������
	int j;
	for (j = 0; j < bombCount; j++)							//����չʾÿ��ը���䶯��
	{
		int bombNum = bombNums[j];
		createSprite(bombNum, "bomb");
		playSpriteAnimate(bombNum, "laser");
		setSpritePosition(bombNum, bombXs[j], bombYs[j]);
	}

	/*�ı�Ԫ��*/
	createText(scoreTextNum, "");							//������ʾ�������ı����󣨳�ʼΪ�մ���
	setTextPosition(scoreTextNum, 0, 570);					//������ʾ�������ı���λ��
	setTextColor(scoreTextNum, 1, 0, 0);					//������ʾ�������ı���λ��
	setTextFontSize(scoreTextNum, 30);						//������ʾ�������ı��������С

	createText(gameOverTextNum, "");						//������ʾ��Ϸ�������ı����󣨳�ʼΪ�մ���
	showText(gameOverTextNum);

	int ateCoinNum = 0;					//��ʼ���Ѿ��Ե��Ľ������
	char message[1000] = "";			//��ʼ����ʾ�������ı�����

	while (1)					
	{
		/*��ȡ�������������ң������ݰ����ƶ�mario����*/
		int a = getPressedKeyCode();						//��ȡ����
		switch (a)
		{
		case RP_KEY_LEFT:									//����Ϊ��
			posX -= 5;										//x�������5
			if (posX < 0)									//�Ƿ�Խ�����
				posX = 0;
			setSpritePosition(marioNum, posX, posY);		//����marioλ��
			setSpriteFlipX(marioNum, FALSE);				//���ĳ��򲻱�
			playSpriteAnimate(marioNum, "walk");			//������·�Ķ���
			break;
		case RP_KEY_RIGHT:									//����Ϊ��
			posX += 5;										//x�����5
			if (posX > gameWidth - spriteWidth)				//�ж��Ƿ�Խ���ҽ�
				posX = gameWidth - spriteWidth;
			setSpritePosition(marioNum, posX, posY);		//����mario��λ��
			setSpriteFlipX(marioNum, TRUE);					//���ĳ�����
			playSpriteAnimate(marioNum, "walk");			//������·����
			break;
		case RP_KEY_UP:										//����Ϊ��
			posY += 5;										//y�����5
			if (posY > gameHeight - spriteHeight)			//�ж��Ƿ�Խ���Ͻ�
				posY = gameHeight - spriteHeight;
			setSpritePosition(marioNum, posX, posY);		//����mario��λ��
			playSpriteAnimate(marioNum, "walk");			//������·����
			break;
		case RP_KEY_DOWN:									//����Ϊ��
			posY -= 5;										//y�������5
			if (posY < 0)									//�ж��Ƿ�Խ���½�
				posY = 0;
			setSpritePosition(marioNum, posX, posY);		//����marioλ��
			playSpriteAnimate(marioNum, "walk");			//������·����
			break;
		default:											//û�а���
			playSpriteAnimate(marioNum, "idle");			//���ž�ֹ����		
			break;
		}

		/*�ж��Ƿ��������*/
		for (i = 0; i < coinCount; i++)
		{
			/*������Һ���Ӧ�����ʧ���Ե��Ľ������һ*/
			if (isSpriteVisible(i + 1) && ((posX - coinXs[i])*(posX - coinXs[i]) + (posY - coinYs[i])*(posY - coinYs[i])) < 100)
			{
				hideSprite(i + 1);
				ateCoinNum++;
			}

			/*���ò�չʾ��Ӧ�ķ�����Ϣ*/
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

		/*�ж��Ƿ�����ը��*/
		for (j = 0; j < bombCount; j++)
		{
			/*����ը���󲥷�fire��������ʾ���յ÷������GameOver����Ϣ���˳���Ϸ*/
			if (((posX - bombXs[j])*(posX - bombXs[j]) + (posY - bombYs[j])*(posY - bombYs[j])) < 100)
			{
				playSpriteAnimate(bombNums[j], "fire");

				/*��ʾ���յ÷����*/
				setText(scoreTextNum, message);
				setTextPosition(scoreTextNum, 0, 270);
				setTextFontSize(scoreTextNum, 30);
				setTextColor(scoreTextNum, 0, 0, 1);

				/*��ʾGameOver*/
				setText(gameOverTextNum, "GAME OVER!");
				setTextPosition(gameOverTextNum, 70, 310);
				setTextFontSize(gameOverTextNum, 35);
				setTextColor(gameOverTextNum, 1, 0, 0);

				/*��ͣ��Ϸ���˳�*/
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