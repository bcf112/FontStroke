#include "Cocos2dxUtil.h"

using namespace cocos2d;

CCRenderTexture* Cocos2dxUtil::createStroke(CCLabelTTF *label, float size, ccColor3B cor){
	CCRenderTexture *rt=CCRenderTexture::create(label->getTexture()->getContentSize().width+size*2, label->getTexture()->getContentSize().height+size*2);
	CCPoint originalPos=label->getPosition();
	ccColor3B originalColor=label->getColor();
	label->setColor(cor);

	ccBlendFunc originalBlendFunc=label->getBlendFunc();

	ccBlendFunc newBlendFunc;
	newBlendFunc.src=GL_ONE;
	newBlendFunc.dst=GL_SRC0_ALPHA;
	label->setBlendFunc(newBlendFunc);

	//label�� anchor ����Ʈ���� storke�� ������ ��ŭ ���� ���� center�� �����Ѵ�.
	CCPoint center=ccp(label->getTexture()->getContentSize().width/2+size, label->getTexture()->getContentSize().height/2+size);

	//begin() �Լ��� �׸��⸦ �����ϴ� �κ�.(starts grabbing)
	rt->begin();
	//stroke�� �׸��� ��ġ�� i�� ��ŭ �̵��ϸ� 360�� ȸ���ϸ� �׸���.
	//�۾� ����Ʈ�� ū ��쿡�� i�� �����ϴ� ���� ���� ���� �ؼ� �����ϰ� �׷��� �� �ֵ��� �ؾ��Ѵ�.
	//label->visit() �Լ��� ȭ�鿡 �׷��ִ� ������ �Ѵ�.
	for(int i=0; i<360; i+=30)
	{
		label->setPosition(ccp(center.x + sin(CC_DEGREES_TO_RADIANS(i))*size, center.y + cos(CC_DEGREES_TO_RADIANS(i))*size));
		label->visit();
	}
	rt->end();

	label->setPosition(originalPos);
	label->setBlendFunc(originalBlendFunc);
	label->setColor(originalColor);
	rt->setPosition(originalPos);

	return rt;
}