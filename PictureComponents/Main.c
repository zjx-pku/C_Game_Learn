#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("PictureComponents");
	setGameSize(1920, 1080);
	createImage(0, "wallhaven-vmpwrl.png");		//����ͼƬԪ�أ�ͼƬ��image�ļ����ڣ�Ȼ���������ɽ��������ֻ�ܼ���PNG��ʽ��ʹ��ͼƬ�����м���
	setImagePosition(0, 10, 1);					//�޸�ͼƬ���½ǵ��λ��
	setImagePosition(0, 0, 0);
	setImageSource(0, "wallhaven-ox9ry7.png");	//�޸�ͼƬԴ
	hideImage(0);								//����ͼƬ
	showImage(0);								//��ʾͼƬ
	int x = getImageX(0);						//���ͼƬ���½ǵ��λ��x����
	int y = getImageY(0);						//���ͼƬ���½ǵ��λ��y����
	int width = getImageWidth(0);				//���ͼƬ���
	int height = getImageHeight(0);				//���ͼƬ�߶�
	int isVisable = isImageVisible(0);			//����ͼƬ�Ƿ�ɼ�
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}