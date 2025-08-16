//
// Created by yareach on 25. 8. 13..
//
#include <unity.h>

extern void test_channel();
extern void test_json();
extern void test_type();

int main(void) {
    UNITY_BEGIN();
    test_channel();
    test_json();
    test_type();
    UNITY_END();
}