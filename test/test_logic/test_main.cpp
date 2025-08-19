//
// Created by yareach on 25. 8. 13..
//
#include <unity.h>

extern void test_channel();
extern void test_json();
extern void test_type();
extern void test_mqtt();
extern void test_string();

int main(void) {
    UNITY_BEGIN();
    test_channel();
    test_json();
    test_type();
    test_mqtt();
    test_string();
    UNITY_END();
}