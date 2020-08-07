#import <UIKit/UIKit.h>
#import <BrightcovePlayerSDK/BCOVPlayerSDKManager.h>
#import <BrightcovePlayerSDK/BCOVPlaybackController.h>
#import <BrightcovePlayerSDK/BCOVPlaybackService.h>
#import <BrightcovePlayerSDK/BCOVPUIPlayerView.h>
#import <BrightcovePlayerSDK/BCOVBasicSessionProvider.h>
#import <BrightcovePlayerSDK/BCOVPlayerSDKManager.h>
#import <BrightcovePlayerSDK/BCOVPUIBasicControlView.h>
#import <BrightcovePlayerSDK/BCOVPlaybackSession.h>
#import <BrightcovePlayerSDK/BCOVPUISlider.h>
#import <BrightcovePlayerSDK/BCOVOfflineVideoManager.h>
#import <BrightcovePlayerSDK/BCOVPUIButton.h>
#import <React/RCTBridge.h>
#import <React/UIView+React.h>
#import <AVKit/AVKit.h>
#import <ma_sdk/ma_sdk-Swift.h>
#import <sys/utsname.h>

@interface BrightcovePlayer : UIView<BCOVOfflineVideoManagerDelegate>

@property (nonatomic) BCOVPlaybackService *playbackService;
@property (nonatomic) id<BCOVPlaybackController> playbackController;
@property (nonatomic) id<BCOVPlaybackSession> playbackSession;
@property (nonatomic) BCOVPUIPlayerView *playerView;
@property (nonatomic) BOOL playing;
@property (nonatomic) BOOL autoPlay;
@property (nonatomic) NSString *playerType;
@property (nonatomic) BOOL disableDefaultControl;
@property (nonatomic) float lastBufferProgress;
@property (nonatomic) float targetVolume;
@property (nonatomic) float targetBitRate;
@property (nonatomic) float targetPlaybackRate;
@property (nonatomic) BOOL playbackServiceDirty;
@property (nonatomic) NSDictionary *mediaInfo;
@property (nonatomic) NSTimeInterval segmentDuration;
@property (nonatomic) AVRoutePickerView *route;
@property (nonatomic) AkamaiMediaAnalytics *analytics;

@property (nonatomic, copy) NSString *referenceId;
@property (nonatomic, copy) NSString *videoId;
@property (nonatomic, copy) NSString *videoToken;
@property (nonatomic, copy) NSString *accountId;
@property (nonatomic, copy) NSString *policyKey;
@property (nonatomic, copy) NSString *playerId;
@property (nonatomic, copy) RCTDirectEventBlock onReady;
@property (nonatomic, copy) RCTDirectEventBlock onMetadataLoaded;
@property (nonatomic, copy) RCTDirectEventBlock onPlay;
@property (nonatomic, copy) RCTDirectEventBlock onPause;
@property (nonatomic, copy) RCTDirectEventBlock onEnd;
@property (nonatomic, copy) RCTDirectEventBlock onProgress;
@property (nonatomic, copy) RCTDirectEventBlock onChangeDuration;
@property (nonatomic, copy) RCTDirectEventBlock onUpdateBufferProgress;
@property (nonatomic, copy) RCTDirectEventBlock onBufferingStarted;
@property (nonatomic, copy) RCTDirectEventBlock onBufferingCompleted;
@property (nonatomic, copy) RCTDirectEventBlock onBeforeEnterFullscreen;
@property (nonatomic, copy) RCTDirectEventBlock onEnterFullscreen;
@property (nonatomic, copy) RCTDirectEventBlock onBeforeExitFullscreen;
@property (nonatomic, copy) RCTDirectEventBlock onExitFullscreen;
@property (nonatomic, copy) RCTDirectEventBlock onError;
@property (nonatomic, copy) RCTDirectEventBlock onNetworkConnectivityChange;
@property (nonatomic, copy) RCTDirectEventBlock onWatchedTime;
@property (nonatomic, copy) RCTDirectEventBlock onRewind;
@property (nonatomic, copy) RCTDirectEventBlock onLiveSelection;

-(void) setPlay:(BOOL)play;
-(void) seekTo:(NSNumber *)time;
-(void) setFullscreen:(BOOL)fullscreen;
-(void) seekToLive;
-(void) setBitRate:(NSNumber *)bitRate;
-(void) createAirplayIconOverlay;
-(void) dispose;

typedef enum {
    title = 0,
    contentLength,
    device,
    playerId,
    eventName
} AnalyticType;

@end
