//
// Created by yareach on 25. 8. 19..
//

#include <unity.h>

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

void test_topic_parsing() {
    RUN_TEST(test_parse_refresh_message);
    RUN_TEST(test_parse_updated_message);
    RUN_TEST(test_parse_channel_info_changed_message);
    RUN_TEST(test_parse_channel_state_changed_message);
    RUN_TEST(test_parse_channel_image_changed_message);
}