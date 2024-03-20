#pragma once

// cpp libs
#include <chrono>
#include <codecvt>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
// osx api
#include <Carbon/Carbon.h>


/**
 * @brier Converts an std::wstring to utr-8 std::string
 * @param wstr The wstring to be converted
 * @return The copnverted string
 */
std::string rawWstringToString(const std::wstring &wstr) {
    return std::string(wstr.begin(), wstr.end());
}

/// @brief Enum describing the state of TIDAL app

enum status { error, closed, opened, playing };


std::wstring ctow(const char *src) {
    std::vector<wchar_t> dest(strlen(src) + 1);
    int i = mbstowcs(&dest[0], src, strlen(src));
    return std::wstring(&dest[0]);
}


/**
 * Attempting to get a Stream of the screen triggering the Screen Recording Permission window on macOS Catalina
 * @return Bool showing presence of permissions for screen recording
 */
bool macPerms() {
    CGDisplayStreamRef stream = CGDisplayStreamCreate(
        CGMainDisplayID(),
        1,
        1,
        'BGRA',
        nil,
        ^(CGDisplayStreamFrameStatus status,
          uint64_t displayTime,
          IOSurfaceRef frameSurface,
          CGDisplayStreamUpdateRef updateRef) {}
    );

    if (stream) {
        CFRelease(stream);
        return true;
    } else {
        return false;
    }
}


/**
 * @brief Checks tidal Info
 * @param song Track name if tidal is playing else empty string
 * @param artist Artist name if tidal is playing else empty string
 * @return returns a <status> struct with current tidal ifno
 */
status tidalInfo(std::wstring &song, std::wstring &artist) {
    char buffer[512] = "";
    int layer = 0;
    status result = closed;
    CFArrayRef windowList = CGWindowListCopyWindowInfo(kCGWindowListOptionAll, kCGNullWindowID);
    CFIndex numWindows = CFArrayGetCount(windowList);
    const std::wregex rgx(L"(.+) - (?!\\{)(.+)");

    song = L"";
    artist = L"";

    for (int i = 0; i < (int) numWindows; i++) {
        auto info = (CFDictionaryRef) CFArrayGetValueAtIndex(windowList, i);
        auto appName = (CFStringRef) CFDictionaryGetValue(info, kCGWindowOwnerName);

        CFNumberGetValue((CFNumberRef) CFDictionaryGetValue(info, kCGWindowLayer), kCFNumberIntType, &layer);

        if (appName != nullptr) {
            CFStringGetCString(appName, buffer, 512, kCFStringEncodingUTF8);
            if (layer == 0 && std::strcmp(buffer, "TIDAL") == 0) {
                char title[512] = "";
                auto windowTitle = (CFStringRef) CFDictionaryGetValue(info, kCGWindowName);
                if (windowTitle != nullptr) {
                    CFStringGetCString(windowTitle, title, sizeof title, kCFStringEncodingUTF8);

                    result = opened;
                    std::wsmatch matches;
                    auto wtitle = std::wstring(title, title + strlen(title));

                    if (std::regex_search(wtitle, matches, rgx)) {
                        song = matches[1].str();
                        artist = matches[2].str();
                        result = playing;
                        goto _exit;
                    }
                }
            }
        }
    }
    _exit:
    return result;
}


/**
 * Gets locale of current user
 * @return ISO 2 letter formated country code
 */
inline char *getLocale() noexcept {
    char *tmp = new char[2];
    auto localeID = (CFStringRef) CFLocaleGetValue(CFLocaleCopyCurrent(), kCFLocaleCountryCode);
    CFStringGetCString(localeID, tmp, 16, kCFStringEncodingUTF8);
    return tmp;
}
