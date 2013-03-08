//
//  ReachabilityManager.m
//  PRXMedia
//
//  Created by Rebecca Nesson on 3/8/13.
//
//

#import "ReachabilityManager.h"
#import "Reachability.h"

@interface ReachabilityManager ()
@property NetworkStatus previousReachability;
@end

@implementation ReachabilityManager

- (id) init {
    self = [super init];
    if (self) {
        _reach = [Reachability reachabilityWithHostname:@"www.google.com"];
        
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(reachabilityDidChange:)
                                                     name:kReachabilityChangedNotification
                                                   object:nil];
        
        self.previousReachability = -1;
        
        [self.reach startNotifier];
    }
    return self;
}

- (void) reachabilityDidChange:(NSNotification *)notification {
    if (self.delegate && [self.delegate respondsToSelector:@selector(reachabilityDidChangeFrom:to:)]) {
        [self.delegate reachabilityDidChangeFrom:self.previousReachability to:self.reach.currentReachabilityStatus]; 
    }
    self.previousReachability = self.reach.currentReachabilityStatus; 
}

@end
