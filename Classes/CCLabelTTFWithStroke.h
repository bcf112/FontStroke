#include "cocos2d.h"

using namespace cocos2d;

class CCLabelTTFWithStroke : public CCLabelTTF
{
public:
	CC_SYNTHESIZE(int, strokeSize, StrokeSize);
	CC_SYNTHESIZE(ccColor3B, strokeColor, StrokeColor);
	CCRenderTexture *createStroke(CCLabelTTF *label, float size, ccColor3B cor);
	void setShadow();
	void setFontName(const char *fontName);
};