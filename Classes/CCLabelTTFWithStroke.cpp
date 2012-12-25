#define kTagStroke 1029384756

#include "CCLabelTTFWithStroke.h"

using namespace cocos2d;


CCRenderTexture* CCLabelTTFWithStroke::createStroke(CCLabelTTF *label, float size, ccColor3B cor)
{
	CCSize labelSize=label->getTexture()->getContentSize();
	CCRenderTexture *rt=CCRenderTexture::create(labelSize.width + size*2, labelSize.height + size*2);
	CCPoint originalPos=label->getPosition();
	ccColor3B originalColor=label->getColor();
	float originalScaleX=label->getScaleX();
	float originalScaleY=label->getScaleY();
	bool originalVisibility=label->isVisible();
	
	label->setColor(cor);
	label->setScale(1.0f);
	label->setVisible(true);
	ccBlendFunc originalBlend=label->getBlendFunc();

	ccBlendFunc setBlend;
	setBlend.dst=GL_ONE;
	setBlend.src=GL_SRC_ALPHA;
	label->setBlendFunc(setBlend);
	CCPoint bottomLeft=ccp(labelSize.width * label->getAnchorPoint().x + size, labelSize.height * label->getAnchorPoint().y + size);
	CCPoint positionOffset=ccp(label->getContentSize().width/2, label->getContentSize().height/2);


	//begin이랑 end가 있는데 뭐하는건지 모르겠다.
	rt->begin();

	label->setPosition(originalPos);
	label->setColor(originalColor);
	label->setBlendFunc(originalBlend);
	label->setVisible(originalVisibility);
	label->setScaleX(originalScaleX);
	label->setScaleY(originalScaleY);
	rt->setPosition(positionOffset);

	return rt;
}

CCLabelTTF *CCLabelTTFWithStroke::create(const char *string, const char *fontName, float fontSize){
	CCLabelTTF* label=CCLabelTTF::create(string, fontName, fontSize);
	setStrokeSize(2);
	setStrokeColor(ccc3(15, 15, 15));
	return label;
}


void CCLabelTTFWithStroke::setFontName(const char *fontName){
	setFontName(fontName);
	this->setShadow();
}

void CCLabelTTFWithStroke::setFontSize(float fontSize){
	setFontSize(fontSize);
	this->setShadow();
}

void CCLabelTTFWithStroke::setOpacity(GLubyte opacity){
	setOpacity(opacity);
	this->setShadow();
}

void CCLabelTTFWithStroke::setShadow(){
	this->removeChildByTag(kTagStroke, true);
	if(!this->getString()){
		return;
	}

	CCRenderTexture *stroke=CCLabelTTFWithStroke::createStroke((CCLabelTTF*)this, getStrokeSize(), getStrokeColor());
	this->addChild(stroke, -1, kTagStroke);
}