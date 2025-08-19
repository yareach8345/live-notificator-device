//
// Created by yareach on 25. 8. 19..
//

#include <exception>
#include <unity.h>

#include "error/bad_topic_error.h"
#include "mqtt/topic.h"

const String refreshed_topic = "chzzk-notification/refreshed-at";
const String updated_topic = "chzzk-notification/updated-at";
const String channel_info_changed_topic = "chzzk-notification/channel/chzzk/afff6e3cc8c1487bc4135bc896811dcc/info-changed";
const String channel_state_changed_topic = "chzzk-notification/channel/chzzk/c0d9723cbb75dc223c6aa8a9d4f56002/state";
const String channel_image_changed_topic = "chzzk-notification/channel/chzzk/ca0551b82e3c45a15012145211bacd21/image";

void test_parse_refresh_message() {
    const MessageType result = get_message_type_from_topic(refreshed_topic);
    TEST_ASSERT_EQUAL(REFRESHED, result);
}

void test_parse_updated_message() {
    const MessageType result = get_message_type_from_topic(updated_topic);
    TEST_ASSERT_EQUAL(UPDATED, result);
}

void test_parse_channel_info_changed_message() {
    const MessageType result = get_message_type_from_topic(channel_info_changed_topic);
    TEST_ASSERT_EQUAL(INFO_CHANGED, result);
}

void test_parse_channel_state_changed_message() {
    const MessageType result = get_message_type_from_topic(channel_state_changed_topic);
    TEST_ASSERT_EQUAL(STATE_CHANGED, result);
}

void test_parse_channel_image_changed_message() {
    const MessageType result = get_message_type_from_topic(channel_image_changed_topic);
    TEST_ASSERT_EQUAL(IMAGE_CHANGED, result);
}

void test_get_channel_id_from_topic() {
    const ChannelId result = get_channel_id_from_topic(channel_info_changed_topic);

    TEST_ASSERT_EQUAL(CHZZK, result.get_platform());
    TEST_ASSERT_EQUAL_STRING("afff6e3cc8c1487bc4135bc896811dcc", result.get_id().c_str());
}

void test_get_channel_id_from_topic_by_not_supported_topic() {
    try {
        const ChannelId result = get_channel_id_from_topic(refreshed_topic);
        TEST_FAIL_MESSAGE("unexcepted success");
    } catch (const BadTopicError& e) {
        TEST_ASSERT_EQUAL_STRING("토픽 'chzzk-notification/refreshed-at'은 유효하지 않습니다. 채널에 관련된 메시지의 토픽만 channel id를 가져올 수 있습니다.", e.what());
    }
}

void test_topic_parsing() {
    RUN_TEST(test_parse_refresh_message);
    RUN_TEST(test_parse_updated_message);
    RUN_TEST(test_parse_channel_info_changed_message);
    RUN_TEST(test_parse_channel_state_changed_message);
    RUN_TEST(test_parse_channel_image_changed_message);
    RUN_TEST(test_get_channel_id_from_topic);
    RUN_TEST(test_get_channel_id_from_topic_by_not_supported_topic);
}