//
// Created by yareach on 25. 8. 13..
//
#include <unity.h>

extern void test_live_state();
extern void test_live_state_parsing();
extern void test_platform();
extern void test_json_field_getter();

int main(void) {
    UNITY_BEGIN();
    test_live_state();
    test_live_state_parsing();
    test_platform();
    test_json_field_getter();
    UNITY_END();
}