//
//  CCLabelTTFWithStroke.h
//
//  Created by Kohashi on 2012/10/31.
//  Copyright 2012Ҵ __MyCompanyName__. All rights reserved.
//
 
#import <Foundation/Foundation.h>
#import "cocos2d.h"
 
@interface CCLabelTTFWithStroke : CCLabelTTF {
}
 
@property (nonatomic) int stokeSize;
@property (nonatomic)ccColor3B strokeColor;
 
 
+(CCRenderTexture*) createStroke: (CCLabelTTF*) label   size:(float)size   color:(ccColor3B)cor;
@end