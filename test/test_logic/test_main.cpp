//
// Created by yareach on 25. 8. 13..
//
#include <unity.h>
#include "channel/test_main.h"
#include "channel/live_close.h"
#include "channel/live_open.h"

extern void test_live_state();

int main(void) {
    UNITY_BEGIN();
    test_live_state();
    return UNITY_END();
}