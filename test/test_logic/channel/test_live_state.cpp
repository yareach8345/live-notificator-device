//
// Created by yareach on 25. 8. 13..
//
#include <unity.h>
#include "channel/live_close.h"
#include "channel/live_open.h"

void test_generate_live_close() {
    const LiveClose live_close;

    TEST_ASSERT_EQUAL(false, live_close.get_is_open());
}

void test_generate_live_open() {
    const LiveOpen live_open("test_title", "testing", 3);

    TEST_ASSERT_EQUAL(true, live_open.get_is_open());
    TEST_ASSERT_EQUAL_STRING("test_title", live_open.get_live_title().c_str());
    TEST_ASSERT_EQUAL_STRING("testing", live_open.get_category().c_str());
    TEST_ASSERT_EQUAL(3, live_open.get_concurrent_user_count());
}

void test_value_in_live_open_class_change() {
    LiveOpen live_open("test_title", "category1", 3);

    const String categoryBeforeChange = live_open.get_category();

    live_open.set_category("category2");

    const String categoryAfterChange = live_open.get_category();

    TEST_ASSERT_EQUAL_STRING("category1", categoryBeforeChange.c_str());
    TEST_ASSERT_EQUAL_STRING("category2", categoryAfterChange.c_str());
}

void test_live_state() {
    RUN_TEST(test_generate_live_close);
    RUN_TEST(test_generate_live_open);
    RUN_TEST(test_value_in_live_open_class_change);
}