//
// Created by yareach on 25. 8. 15..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_PLATFORM_H
#define LIVE_NOTIFICATOR_DEVICE_PLATFORM_H

#include "type/string.h"

enum Platform {
    CHZZK,
    YOUTUBE,
};

class PlatformUtils {
public:
    static String to_string(Platform platform);
    static Platform from_string(const String& platform);
};

#endif //LIVE_NOTIFICATOR_DEVICE_PLATFORM_H