#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("΢�Ŵ�ɻ�");
	setGameSize(600, 600);
	createImage(0, "mouse.png");		//����ͼƬ������׼����
	hideMouseCursor();					//�������ָ��
	while (1)
	{
		int x = getMousePositionX();	//ʵʱ��ȡ���x����
		int y = getMousePositionY();	//ʵʱ��ȡ���y����
		setImagePosition(0, x - getImageWidth(0) / 2, y - getImageHeight(0) / 2); //�������λ������ͼƬλ��
	}
	int isDown = isMouseLeftButtonDown();//�ж��������Ƿ���
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}