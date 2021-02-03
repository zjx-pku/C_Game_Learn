#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("TextComponents");		//������Ϸ����
	setGameSize(192, 108);		//������Ϸ���С���Ⱥ����
	createText(0, "PKU");		//�����ı����󣬶�Ӧ����Ϊ0
	setTextPosition(0, 50, 50);	//�����ı�λ�ã���һ��Ԫ��Ϊ�ı�������������ڶ�����Ԫ��Ϊλ��x,y
	setTextFontSize(0, 50);		//���������С����һ��Ԫ��Ϊ�ı�������������ڶ�������Ϊ�����С
	setText(0, "THU");			//�޸��ı����������
	hideText(0);				//�����ı�����
	showText(0);				//��ʾ�ı�����
	setTextColor(0, 1.0f, 0.0f, 0.0f);		//�����ı��������ɫ(r,g,b)��ȡֵ[0,1]
	int x = getTextX(0);					//�����ı������x����
	int y = getTextY(0);					//�����ı������y����
	int isTextVisable = isTextVisible(0);	//�����ı������Ƿ�ɼ�
	pauseGame(10000);						//��ͣ1000����
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}