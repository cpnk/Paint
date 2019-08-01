//
//  EllipseInstrument.m
//  Paint
//
//  Created by Ilya on 7/30/19.
//  Copyright © 2019 Ilya. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EllipseInstrument.h"

@implementation EllipseInstrument

@synthesize pointArray;
@synthesize rect;
@synthesize path;

-(void)drawAlgoritm:(NSMutableArray*) array
{
    CGPoint myStartPoint = CGPointFromString([array objectAtIndex:0]);
    CGPoint myEndPoint = CGPointFromString([array objectAtIndex:[array count] - 1]);
    
    CGFloat h = myEndPoint.x - myStartPoint.x;
    CGFloat w = myEndPoint.y - myStartPoint.y;
    
    [self calcPoints:&myStartPoint endPoint:&myEndPoint];
    
    rect = CGRectMake(myStartPoint.x,
                      myStartPoint.y,
                      fabs(h),
                      fabs(w));
    
    CGPathAddEllipseInRect(path, NULL, rect);
    [self calcRect:&(rect)];
}

@end
