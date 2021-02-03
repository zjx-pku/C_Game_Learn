#include <stdlib.h>
#include <stdio.h>
#include <yzkgame.h>

#pragma comment( linker, "/subsystem:\"console\" /entry:\"mainCRTStartup\"" )
#pragma comment(lib, "YZKGame.lib")

void gameMain(void)
{
	setGameTitle("AnimationComponents");
	setGameSize(338, 600);
	createSprite(0, "girl");		//������������ļ���SpritesĿ¼�£���������Ҫ���ļ�����һ��
	playSpriteAnimate(0, "dance1");	//���ž��鶯������������Ҫ���ļ�����һ�¡�Ĭ��һֱ���Ŷ���
	setSpriteRepeatPlay(0, FALSE);	//�����Ƿ��ظ����Ŷ�����false��ʾֻ����һ��
	setSpritePosition(0, 100, 20);	//���ö��������½�λ�ã�ͼƬΪ���Σ�
	setSpriteFlipX(0, TRUE);		//�����Ƿ���x�᷽���Ϸ�ת�����ԭʼͼƬ��˵��
	setSpriteFlipY(0, TRUE);		//�����Ƿ���y�᷽���Ϸ�ת�����ԭʼͼƬ��˵��
	int x = getSpriteX(0);			//�������½ǵ��x����
	int y = getSpriteY(0);			//�������½ǵ��y����
	int width = getSpriteWidth(0);	//ͼƬ���
	int height = getSpriteHeight(0);//ͼƬ�߶�
	hideSprite(0);					//����ͼƬ
	showSprite(0);					//��ʾͼƬ
	int isVisable = isSpriteVisible(0);//ͼƬ�Ƿ�ɼ�

	pauseGame(10000);
}

int main(void)
{
	rpInit(gameMain);
	return 0;
}