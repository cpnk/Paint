//
//  StarInstrument.h
//  Paint
//
//  Created by Ilya on 7/25/19.
//  Copyright © 2019 Ilya. All rights reserved.
//

#import "InstrumentProtocol.h"

@interface StarInstrument : NSObject <InstrumentProtocol>{
    NSMutableArray *pointArray;
    NSMutableArray *lineArray;
    CGPoint myBeginPoint;
}
@end

@implementation StarInstrument

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
                
                
                CGFloat xCenter = (myStartPoint.x + (myEndPoint.x - myStartPoint.x)/2 );
                CGFloat yCenter = (myStartPoint.y + (myEndPoint.y - myStartPoint.y)/2 );
                
                
                float w = sqrt(pow((myEndPoint.x - myStartPoint.x),2) + pow((myEndPoint.y - myStartPoint.y),2)) ;
                double r = w / 2.0;
                float flip = -1.0;
                
                CGContextSetFillColorWithColor(context, [[UIColor blackColor] CGColor]);
                
                CGContextSetStrokeColorWithColor(context, [[UIColor blackColor] CGColor]);
                
                double theta = 2.0 * M_PI * (2.0 / 5.0); // 144 degrees
                
                CGContextMoveToPoint(context, xCenter, r*flip+yCenter);
                
                for (NSUInteger k=1; k<5; k++)
                {
                    float x = r * sin(k * theta);
                    float y = r * cos(k * theta);
                    CGContextAddLineToPoint(context, x+xCenter, y*flip+yCenter);
                }
                
                CGContextClosePath(context);
                CGContextFillPath(context);
                
 
               // CGRect rect = CGRectMake (myStartPoint.x, myStartPoint.y, (myEndPoint.x - myStartPoint.x), (myEndPoint.y - myStartPoint.y));
               // CGContextAddRect(context, rect);
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
        
        CGFloat xCenter = (myStartPoint.x + (myEndPoint.x - myStartPoint.x)/2 );
        CGFloat yCenter = (myStartPoint.y + (myEndPoint.y - myStartPoint.y)/2 );
        
        float w = sqrt(pow((myEndPoint.x - myStartPoint.x),2) + pow((myEndPoint.y - myStartPoint.y),2)) ;
        double r = w / 2.0;
        float flip = -1.0;
        
        CGContextSetFillColorWithColor(context, [[UIColor blackColor] CGColor]);
        
        CGContextSetStrokeColorWithColor(context, [[UIColor blackColor] CGColor]);
        
        double theta = 2.0 * M_PI * (2.0 / 5.0); // 144 degrees
        
        CGContextMoveToPoint(context, xCenter, r*flip+yCenter);
        
        for (NSUInteger k=1; k<5; k++)
        {
            float x = r * sin(k * theta);
            float y = r * cos(k * theta);
            CGContextAddLineToPoint(context, x+xCenter, y*flip+yCenter);
        }
        
        CGContextClosePath(context);
        CGContextFillPath(context);;
        
        //CGRect rect = CGRectMake (myStartPoint.x, myStartPoint.y, (myEndPoint.x - myStartPoint.x), (myEndPoint.y - myStartPoint.y));
       // CGContextAddRect(context, rect);
        
        CGContextSetStrokeColorWithColor(context,[[UIColor blackColor] CGColor]);
        CGContextSetLineWidth(context, 8.0);
        CGContextStrokePath(context);
    }
    
    
    
    
}




@synthesize lineArray;

@synthesize myBeginPoint;

@synthesize pointArray;

@end