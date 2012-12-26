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

	//label의 anchor 포인트에서 storke의 사이즈 만큼 더한 값을 center에 저장한다.
	CCPoint center=ccp(label->getTexture()->getContentSize().width/2+size, label->getTexture()->getContentSize().height/2+size);

	//begin() 함수는 그리기를 시작하는 부분.(starts grabbing)
	rt->begin();
	//stroke를 그리는 위치를 i도 만큼 이동하며 360도 회전하며 그린다.
	//글씨 포인트가 큰 경우에는 i가 증가하는 값의 폭을 적게 해서 세밀하게 그려질 수 있도록 해야한다.
	//label->visit() 함수는 화면에 그려주는 역할을 한다.
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