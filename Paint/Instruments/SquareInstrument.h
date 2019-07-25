//
//  SquareInstrument.h
//  Paint
//
//  Created by Ilya on 7/25/19.
//  Copyright © 2019 Ilya. All rights reserved.
//

#include <math.h>
#import "InstrumentProtocol.h"
#import "StateManager.h"

@interface SquareInstrument : NSObject <InstrumentProtocol>{
    NSMutableArray *pointArray;
    NSMutableArray *lineArray;
    CGPoint myBeginPoint;
}
@end

@implementation SquareInstrument

- (id)init
{
    if (self = [super init]) {
        pointArray=[[NSMutableArray alloc]init];
        lineArray=[[NSMutableArray alloc]init];
    }
    return self;
}

- (void)draw {
    
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextBeginPath(context);
    CGContextSetLineWidth(context, 8.0f);
    
    CGContextSetLineJoin(context, kCGLineJoinRound);
    CGContextSetLineCap(context, kCGLineCapRound);
    
    if ([lineArray count] > 0) {
        for (int i = 0; i < [lineArray count]; i++) {
            NSArray * array = [NSArray arrayWithArray:[lineArray objectAtIndex:i]];
            if ([array count] > 0) {
                CGContextBeginPath(context);
                CGPoint myStartPoint = CGPointFromString([array objectAtIndex:0]);
                
                CGPoint myEndPoint = CGPointFromString([array objectAtIndex:[array count] - 1]);
       
                CGRect rect = CGRectMake (myStartPoint.x, myStartPoint.y, myEndPoint.x - myStartPoint.x, myEndPoint.x - myStartPoint.x);
                CGContextAddRect(context, rect);
                
                CGContextSetStrokeColorWithColor(context,[[UIColor blackColor] CGColor]);
                CGContextSetLineWidth(context, 8.0);
                CGContextStrokePath(context);
            }
        }
    }
    
    if ([pointArray count] > 0) {
        CGContextBeginPath(context);
        CGPoint myStartPoint = CGPointFromString([pointArray objectAtIndex:0]);
        CGContextMoveToPoint(context, myStartPoint.x, myStartPoint.y);
        
        CGPoint myEndPoint = CGPointFromString([pointArray objectAtIndex:[pointArray count] - 1]);
    
        CGRect rect = CGRectMake (myStartPoint.x, myStartPoint.y, myEndPoint.x - myStartPoint.x, myEndPoint.x - myStartPoint.x);
        CGContextAddRect(context, rect);
        
        CGContextSetStrokeColorWithColor(context,[[UIColor blackColor] CGColor]);
        CGContextSetLineWidth(context, 8.0);
        CGContextStrokePath(context);
    }
    
    
}

@end
