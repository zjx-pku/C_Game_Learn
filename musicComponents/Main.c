#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("΢�Ŵ�ɻ�");
	setGameSize(338, 600);
	playSound("��������.mp3",TRUE); //�������֣�ͨ�����ƽ�������������ֵ�����Ƿ��ظ����ţ���̨���֣���������Ϻ������У�
									//���е�playSound���в���
	pauseGame(10000);
	closeSound("��������.mp3");		//�رղ��ŵ�����

	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}