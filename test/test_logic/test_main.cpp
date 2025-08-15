//
// Created by yareach on 25. 8. 13..
//
#include <unity.h>

extern void test_channel();
extern void test_json();

int main(void) {
    UNITY_BEGIN();
    test_channel();
    test_json();
    UNITY_END();
}