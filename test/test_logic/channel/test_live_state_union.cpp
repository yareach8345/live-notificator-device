//
// Created by yareach on 25. 8. 17..
//

#include <unity.h>
#include "channel/live_state_union.h"

void test_live_close() {
    LiveClose close = {};
    LiveStateUnion state(close);

    TEST_ASSERT_EQUAL(false, state.close.get_is_open());
    TEST_ASSERT_EQUAL(LiveStateType::CLOSE, state.close.get_live_state_type());
}

void test_live_open() {
    LiveOpen open("testing", "test", 999);
    LiveStateUnion state(open);

    TEST_ASSERT_EQUAL(true, state.open.get_is_open());
    TEST_ASSERT_EQUAL_STRING("testing", state.open.get_live_title().c_str());
    TEST_ASSERT_EQUAL_STRING("test", state.open.get_category().c_str());
    TEST_ASSERT_EQUAL(999, state.open.get_concurrent_user_count());
    TEST_ASSERT_EQUAL(LiveStateType::OPEN, state.open.get_live_state_type());
}

void test_live_state_union() {
    RUN_TEST(test_live_close);
    RUN_TEST(test_live_open);
}