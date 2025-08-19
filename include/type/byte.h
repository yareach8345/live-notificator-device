//
// Created by yareach on 25. 8. 19..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_BYTE_H
#define LIVE_NOTIFICATOR_DEVICE_BYTE_H

#ifdef ESP32_ENV
#include <Arduino.h>
#elif NATIVE_ENV
#include <cstdint>
typedef uint8_t byte;
#endif

#endif //LIVE_NOTIFICATOR_DEVICE_BYTE_H