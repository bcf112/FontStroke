//
//  CCLabelTTFWithStroke.m
//  zoffy
//
//  Created by Daisuke Kohashi on 2012/10/31.
//  Copyright 2012Ҵ __MyCompanyName__. All rights reserved.
//
 
#import "CCLabelTTFWithStroke.h"
 
 
@implementation CCLabelTTFWithStroke
 
@synthesize stokeSize = _stokeSize;
@synthesize strokeColor = _strokeColor;
 
#define kTagStroke 1029384756
 
+(CCRenderTexture*) createStroke: (CCLabelTTF*) label   size:(float)size   color:(ccColor3B)cor
{
	CCRenderTexture* rt = [CCRenderTexture renderTextureWithWidth:label.texture.contentSize.width+size*2  height:label.texture.contentSize.height+size*2];
	CGPoint originalPos = [label position];
	ccColor3B originalColor = [label color];
    float originalScaleX = [label scaleX];
    float originalScaleY = [label scaleY];
	BOOL originalVisibility = [label visible];
	[label setColor:cor];
    [label setScale:1];
	[label setVisible:YES];
	ccBlendFunc originalBlend = [label blendFunc];
	[label setBlendFunc:(ccBlendFunc) { GL_SRC_ALPHA, GL_ONE }];
	CGPoint bottomLeft = ccp(label.texture.contentSize.width * label.anchorPoint.x + size, label.texture.contentSize.height * label.anchorPoint.y + size);
    CGPoint positionOffset= ccp(label.contentSize.width/2, label.contentSize.height/2);
    
	[rt begin];
	for (int i=0; i<360; i+=45) // you should optimize that for your needs
	{
        
		[label setPosition:ccp(bottomLeft.x + sin(CC_DEGREES_TO_RADIANS(i))*size, bottomLeft.y + cos(CC_DEGREES_TO_RADIANS(i))*size)];
		[label visit];
	}
    
    
	[rt end];
	[label setPosition:originalPos];
	[label setColor:originalColor];
	[label setBlendFunc:originalBlend];
	[label setVisible:originalVisibility];
    [label setScaleX: originalScaleX];
    [label setScaleY: originalScaleY];
    rt.position = positionOffset;
    
	return rt;
}
 
//----------
-(id)init{
    id my = [super init];
    _stokeSize = 2;
    _strokeColor = ccc3(15, 15, 15);
    return my;
}
 
-(void)setFontName:(NSString *)fontName{
    [super setFontName:fontName];
    [self setShadow];
}
-(void)setFontSize:(float)fontSize{
    [super setFontSize:fontSize];
    [self setShadow];
}
-(void) setString:(NSString *)string
{
	[super setString:string];
    [self setShadow];
}
 
-(void)setOpacity:(GLubyte)opacity{
    [super setOpacity:opacity];
    [self setShadow];
}
 
-(void) setShadow
{
    [self removeChildByTag:kTagStroke cleanup:YES];
    if(!self.string) return;
    CCRenderTexture * stroke  = [CCLabelTTFWithStroke createStroke:(CCLabelTTF*)self size:_stokeSize color:_strokeColor];
    [self addChild:stroke z:-1 tag:kTagStroke];
}
 
@end