//
// Created by yareach on 25. 8. 17..
//

#include "channel/live_state_variant.h"
#include <unity.h>

void test_generate_live_state_variant_bye_close() {
    LiveClose close = {};
    LiveStateVariant state(close);

    TEST_ASSERT_EQUAL(false, state.get_live_state_by_close().get_is_open());
    TEST_ASSERT_EQUAL(LiveStateType::CLOSE, state.get_live_state_by_close().get_live_state_type());
}

void test_generate_live_state_variant_by_open() {
    LiveOpen open("testing", "test", 999);
    LiveStateVariant state(open);

    TEST_ASSERT_EQUAL(true, state.get_live_state_by_open().get_is_open());
    TEST_ASSERT_EQUAL_STRING("testing", state.get_live_state_by_open().get_live_title().c_str());
    TEST_ASSERT_EQUAL_STRING("test", state.get_live_state_by_open().get_category().c_str());
    TEST_ASSERT_EQUAL(999, state.get_live_state_by_open().get_concurrent_user_count());
    TEST_ASSERT_EQUAL(LiveStateType::OPEN, state.get_live_state_by_open().get_live_state_type());
}

void test_change_live_state_from_open_to_open() {
    LiveStateVariant state(LiveOpen("testing1", "test1", 999));

    LiveStateType live_state_type_before_change = state.get_live_state_type();
    LiveOpen before_change = state.get_live_state_by_open();

    state.set_live_state(LiveOpen("testing2", "test2", 123));

    TEST_ASSERT_EQUAL(OPEN, live_state_type_before_change);
    TEST_ASSERT_EQUAL_STRING("testing1", before_change.get_live_title().c_str());
    TEST_ASSERT_EQUAL_STRING("test1", before_change.get_category().c_str());
    TEST_ASSERT_EQUAL(999, before_change.get_concurrent_user_count());

    TEST_ASSERT_EQUAL(OPEN, state.get_live_state_type());
    TEST_ASSERT_EQUAL_STRING("testing2", state.get_live_state_by_open().get_live_title().c_str());
    TEST_ASSERT_EQUAL_STRING("test2", state.get_live_state_by_open().get_category().c_str());
    TEST_ASSERT_EQUAL(123, state.get_live_state_by_open().get_concurrent_user_count());
}

void test_change_live_state_from_open_to_close() {
    LiveStateVariant state(LiveOpen("testing", "test", 123));

    LiveStateType live_state_type_before_change = state.get_live_state_type();
    LiveOpen before_change = state.get_live_state_by_open();

    state.set_live_state(LiveClose());

    TEST_ASSERT_EQUAL(OPEN, live_state_type_before_change);
    TEST_ASSERT_EQUAL_STRING("testing", before_change.get_live_title().c_str());
    TEST_ASSERT_EQUAL_STRING("test", before_change.get_category().c_str());
    TEST_ASSERT_EQUAL(123, before_change.get_concurrent_user_count());

    TEST_ASSERT_EQUAL(CLOSE, state.get_live_state_type());
}

void test_change_live_state_from_close_to_open() {
    LiveClose close;
    LiveStateVariant state(close);

    LiveStateType live_state_type_before_change = state.get_live_state_type();

    LiveOpen open = LiveOpen("testing", "test", 123);
    state.set_live_state(open);

    TEST_ASSERT_EQUAL(CLOSE, live_state_type_before_change);

    TEST_ASSERT_EQUAL(OPEN, state.get_live_state_type());
    TEST_ASSERT_EQUAL_STRING("testing", state.get_live_state_by_open().get_live_title().c_str());
    TEST_ASSERT_EQUAL_STRING("test", state.get_live_state_by_open().get_category().c_str());
    TEST_ASSERT_EQUAL(123, state.get_live_state_by_open().get_concurrent_user_count());
}

void test_live_state_variant() {
    RUN_TEST(test_generate_live_state_variant_bye_close);
    RUN_TEST(test_generate_live_state_variant_by_open);
    RUN_TEST(test_change_live_state_from_open_to_open);
    RUN_TEST(test_change_live_state_from_open_to_close);
    RUN_TEST(test_change_live_state_from_close_to_open);
}
