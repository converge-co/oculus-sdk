/***********************************************************************

Filename    :   OSX_PlatformObjc.h
Content     :
Created     :
Authors     :

Copyright   :   Copyright 2012 Oculus VR, LLC. All Rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

************************************************************************/

#import <Cocoa/Cocoa.h>
#import "OSX_Platform.h"
#import "OSX_Gamepad.h"

#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGDirectDisplay.h>

@interface OVRApp : NSApplication
{
    NSWindow* _win;
    OVR::OvrPlatform::OSX::PlatformCore* _Platform;
    OVR::OvrPlatform::Application* _App;
};

@property (assign) IBOutlet NSWindow* win;
@property (assign) OVR::OvrPlatform::OSX::PlatformCore* Platform;
@property (assign) OVR::OvrPlatform::Application* App;

-(void) run;

@end

@interface OVRView : NSOpenGLView <NSWindowDelegate>
{
    OVR::OvrPlatform::OSX::PlatformCore* _Platform;
    OVR::OvrPlatform::Application* _App;
    NSOpenGLPixelFormat* _PixelFormat;
    unsigned long _Modifiers;
}

@property (assign) OVR::OvrPlatform::OSX::PlatformCore* Platform;
@property (assign) OVR::OvrPlatform::Application* App;
@property unsigned long Modifiers;

-(void)ProcessMouse:(NSEvent*)event;
-(void)warpMouseToCenter;
-(void)setApp:(OVR::OvrPlatform::Application*)app;
-(void)setPlatform:(OVR::OvrPlatform::OSX::PlatformCore*)platform;
-(NSOpenGLPixelFormat*)getPixelFormat;

+(CGDirectDisplayID) displayFromScreen:(NSScreen*)s;

@end

