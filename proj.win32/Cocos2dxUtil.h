#include "cocos2d.h"

using namespace cocos2d;

class Cocos2dxUtil
{
public:
	//label�� stroke ȿ���� ��������ִ� �Լ�
	//����� �� stroke�� ���� �׸��� label�� �׷��� �Ѵ�.
	static CCRenderTexture* createStroke(CCLabelTTF *label, float size, ccColor3B cor);
};