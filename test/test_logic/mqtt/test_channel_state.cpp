//
// Created by yareach on 25. 8. 20..
//

#include <unity.h>

#include "error/parsing_fail_error.h"
#include "mqtt/channel_state.h"

void test_transform_from_string_to_channel_state() {
    const ChannelState open_parsing_result = ChannelStateUtils::from_string("open");
    const ChannelState closed_parsing_result = ChannelStateUtils::from_string("closed");
    const ChannelState added_parsing_result = ChannelStateUtils::from_string("added");
    const ChannelState deleted_parsing_result = ChannelStateUtils::from_string("deleted");

    TEST_ASSERT_EQUAL(OPEN, open_parsing_result);
    TEST_ASSERT_EQUAL(CLOSE, closed_parsing_result);
    TEST_ASSERT_EQUAL(ADDED, added_parsing_result);
    TEST_ASSERT_EQUAL(DELETED, deleted_parsing_result);
}

void test_try_transform_to_channel_state_with_unknown_state() {
    try {
        const ChannelState result = ChannelStateUtils::from_string("unknown");
        TEST_FAIL_MESSAGE("unexcepted success");
    } catch (const ParsingFailError& e) {
        TEST_ASSERT_EQUAL_STRING("ChannelState 파싱 실패. 문자열 'unknown'는 ChannelState로 파싱될 수 없습니다.", e.what());
    }
}

void test_transform_from_channel_state_to_string() {
    const String open_result = ChannelStateUtils::to_string(OPEN);
    const String closed_result = ChannelStateUtils::to_string(CLOSE);
    const String added_result = ChannelStateUtils::to_string(ADDED);
    const String deleted_result = ChannelStateUtils::to_string(DELETED);

    TEST_ASSERT_EQUAL_STRING("open", open_result.c_str());
    TEST_ASSERT_EQUAL_STRING("closed", closed_result.c_str());
    TEST_ASSERT_EQUAL_STRING("added", added_result.c_str());
    TEST_ASSERT_EQUAL_STRING("deleted", deleted_result.c_str());
}

void test_channel_state() {
    RUN_TEST(test_transform_from_string_to_channel_state);
    RUN_TEST(test_try_transform_to_channel_state_with_unknown_state);
    RUN_TEST(test_transform_from_channel_state_to_string);
}