//
//  PRXPlayer_private.h
//  PRXPlayer
//
//  Copyright (c) 2013 PRX.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

@import MediaPlayer;

#import "PRXPlayer.h"

@interface PRXPlayer ()

+ (dispatch_queue_t)sharedObserverQueue;
+ (dispatch_queue_t)sharedAssignmentQueue;

@property (nonatomic, strong, readonly) Reachability *reach;
@property (nonatomic, strong) AVPlayer *player;

@property (nonatomic, readonly) float rateForFilePlayback;
@property (nonatomic, readonly) float rateForPlayback;

@property (nonatomic, readonly) BOOL allowsPlaybackViaWWAN;

@property (nonatomic, strong, readonly) NSDictionary *MPNowPlayingInfoCenterNowPlayingInfo;

- (void)postGeneralChangeNotification;

- (void)mediaPlayerCurrentItemStatusDidChange:(NSDictionary *)change;
- (void)mediaPlayerCurrentItemDidPlayToEndTime:(NSNotification *)notification;

@end
