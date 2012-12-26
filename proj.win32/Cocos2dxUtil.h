#include "cocos2d.h"

using namespace cocos2d;

class Cocos2dxUtil
{
public:
	//label에 stroke 효과를 적용시켜주는 함수
	//사용할 때 stroke를 먼저 그리고 label을 그려야 한다.
	static CCRenderTexture* createStroke(CCLabelTTF *label, float size, ccColor3B cor);
};