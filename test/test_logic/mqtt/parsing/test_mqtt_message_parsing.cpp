//
// Created by yareach on 25. 8. 20..
//

#include <unity.h>
#include "mqtt/parser.h"
#include "mqtt/message/channel_image_changed_message.h"
#include "mqtt/message/channel_info_changed_message.h"
#include "mqtt/message/channel_state_changed_message.h"
#include "mqtt/message/updated_message.h"

// topic:
// chzzk-notification/refreshed-at

// topic:
// chzzk-notification/updated-at

// topic:
// chzzk-notification/channel/chzzk/afff6e3cc8c1487bc4135bc896811dcc/info-changed
//
// messages:
// {\"concurrentUserCount\":106}
// {\"followerCount\":49758}

// topic:
// chzzk-notification/channel/chzzk/afff6e3cc8c1487bc4135bc896811dcc/state
//
// messages:
// open
// closed

void test_update_message_parsing() {
    const MqttMessage update("chzzk-notification/updated-at", "ssss");

    const MessageBase *parsing_result = parse_message(update);

    TEST_ASSERT_EQUAL(UPDATED, parsing_result->get_message_type());
}

void test_refreshed_message_parsing() {
    const MqttMessage refresh("chzzk-notification/refreshed-at", "ssss");

    const MessageBase *parsing_result = parse_message(refresh);

    TEST_ASSERT_EQUAL(REFRESHED, parsing_result->get_message_type());
}

void test_channel_info_changed_message_parsing() {
    const MqttMessage channel_info_changed("chzzk-notification/channel/chzzk/test-user/info-changed", "{\"concurrentUserCount\":106}");

    const MessageBase *parsing_result = parse_message(channel_info_changed);
    const ChannelInfoChangedMessage *info_changed_message = dynamic_cast<const ChannelInfoChangedMessage *>(parsing_result);

    TEST_ASSERT_EQUAL(INFO_CHANGED, parsing_result->get_message_type());

    TEST_ASSERT_EQUAL(CHZZK, info_changed_message->get_channel_id().get_platform());
    TEST_ASSERT_EQUAL_STRING("test-user", info_changed_message->get_channel_id().get_id().c_str());

    TEST_ASSERT_EQUAL(1, info_changed_message->get_updates().size());
    TEST_ASSERT_EQUAL(false, info_changed_message->get_updates()["concurrentUserCount"].isNull());
    TEST_ASSERT_EQUAL(106, info_changed_message->get_updates()["concurrentUserCount"].as<long>());
}

void test_channel_state_changed_message_parsing() {
    const MqttMessage channel_state_changed("chzzk-notification/channel/youtube/test-user/state", "open");

    const MessageBase *parsing_result = parse_message(channel_state_changed);
    const ChannelStateChangedMessage *state_changed_message = dynamic_cast<const ChannelStateChangedMessage *>(parsing_result);

    TEST_ASSERT_EQUAL(STATE_CHANGED, parsing_result->get_message_type());

    TEST_ASSERT_EQUAL(YOUTUBE, state_changed_message->get_channel_id().get_platform());
    TEST_ASSERT_EQUAL_STRING("test-user", state_changed_message->get_channel_id().get_id().c_str());
    TEST_ASSERT_EQUAL(OPEN, state_changed_message->get_new_state());
}

void test_channel_image_changed_message_parsing() {
    const MqttMessage channel_image_changed("chzzk-notification/channel/chzzk/test-user/image", "changed");

    const MessageBase *parsing_result = parse_message(channel_image_changed);
    const ChannelImageChangedMessage *image_changed_message = dynamic_cast<const ChannelImageChangedMessage *>(parsing_result);

    TEST_ASSERT_EQUAL(IMAGE_CHANGED, parsing_result->get_message_type());

    TEST_ASSERT_EQUAL(CHZZK, image_changed_message->get_channel_id().get_platform());
    TEST_ASSERT_EQUAL_STRING("test-user", image_changed_message->get_channel_id().get_id().c_str());
}

void test_mqtt_message_parsing() {
    RUN_TEST(test_update_message_parsing);
    RUN_TEST(test_refreshed_message_parsing);
    RUN_TEST(test_channel_info_changed_message_parsing);
    RUN_TEST(test_channel_state_changed_message_parsing);
    RUN_TEST(test_channel_image_changed_message_parsing);
}