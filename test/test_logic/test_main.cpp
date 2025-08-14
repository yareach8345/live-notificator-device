//
// Created by yareach on 25. 8. 13..
//
#include <unity.h>

extern void test_live_state();
extern void test_live_state_parsing();

int main(void) {
    UNITY_BEGIN();
    test_live_state();
    test_live_state_parsing();
    return UNITY_END();
}