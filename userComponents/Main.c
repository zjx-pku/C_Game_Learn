#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{

	if (confirm("���Ǻ�����"))								//ѯ�ʺ���������û�������ǡ����򷵻�ֵΪ1�����򷵻�ֵΪ0
	{
		alert("��ã���ӭ����C���Ե����硣�ҵ�������%s", "�Ž�ѧ");	//��ʾ��Ϣ���Ǹ�����������ֻ�е��ȷ�������Ż���������
	}
	else
	{
		alert("���Ǹ��󻵵������֣�");
	}
	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}