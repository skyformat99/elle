//
//  AddInfinitToFavorite.h
//  HelperTools
//
//  Created by Charles Guillot - Infinit on 3/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "FISwizzle.h"
#import "CDStructures.h"

@interface FIAddInfinitToFavorite : NSObject

+ (FIAddInfinitToFavorite*) instance;

+(id)nodeRefWithFENode:(TFENode*)fn;
+(TFENode*)feNodeWithNodeRef:(void*)fn;
+(TFENode*)feNodeWithPath:(NSString*)path;
+(TFENode*)feNodeWithFINode:(id)nd;

@end
