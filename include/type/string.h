//
// Created by yareach on 25. 8. 14..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_STRING_H
#define LIVE_NOTIFICATOR_DEVICE_STRING_H

#ifdef ESP32_ENV
#include <WString.h>
#elif NATIVE_ENV
#include <string>
typedef std::string String;
#endif

#endif //LIVE_NOTIFICATOR_DEVICE_STRING_H