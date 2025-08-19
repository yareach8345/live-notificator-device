//
// Created by yareach on 25. 8. 19..
//

#ifdef ESP32_ENV
#define NATIVE_ENV

#include <HardwareSerial.h>

extern void test_run();

void setup() {
    Serial.begin(115200);
    test_run();
}

void loop() {}

#endif