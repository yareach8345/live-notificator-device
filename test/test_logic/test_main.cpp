//
// Created by yareach on 25. 8. 13..
//
#include <unity.h>

extern void test_channel();
extern void test_json();
extern void test_type();
extern void test_mqtt();

int main(void) {
    UNITY_BEGIN();
    test_channel();
    test_json();
    test_type();
    test_mqtt();
    UNITY_END();
}