#include <Carbon/Carbon.h>
#include "./switch_input_method.h"

static NSMutableString* prevMethod = [[NSMutableString alloc] init];

bool switchEnglishInputMethod () {
    TISInputSourceRef currentSource = TISCopyCurrentKeyboardInputSource();
    [prevMethod setString:(__bridge NSString *)(TISGetInputSourceProperty(currentSource, kTISPropertyInputSourceID))];

    NSArray* sources = CFBridgingRelease(TISCreateInputSourceList((__bridge CFDictionaryRef)@{ (__bridge NSString*)kTISPropertyInputSourceID : @"com.apple.keylayout.ABC" }, false));
    TISInputSourceRef source = (__bridge TISInputSourceRef)sources[0];

    OSStatus status = TISSelectInputSource(source);
    return status == noErr;
}

bool restorePreviousInputMethods() {
    if ([prevMethod length] == 0) {
        return false;
    }
    NSArray* sources = CFBridgingRelease(TISCreateInputSourceList((__bridge CFDictionaryRef)@{ (__bridge NSString*)kTISPropertyInputSourceID : prevMethod }, false));
    TISInputSourceRef source = (__bridge TISInputSourceRef)sources[0];

    OSStatus status = TISSelectInputSource(source);
    return status == noErr;
}
