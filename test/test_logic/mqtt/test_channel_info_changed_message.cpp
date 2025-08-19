//
// Created by yareach on 25. 8. 18..
//

#include <unity.h>
#include "mqtt/message/channel_info_changed_message.h"
#include "json/util.h"

void test_channel_info_changed_message_generate() {
    const String updates_json = "{\"field1\":13, \"field2\":\"new_value\"}";
    const JsonDocument updates = parse_json_string(updates_json);
    ChannelInfoChangedMessage message(ChannelId(CHZZK, "12345"), updates);

    TEST_ASSERT_EQUAL(MessageType::INFO_CHANGED, message.get_message_type());
    TEST_ASSERT_EQUAL(CHZZK, message.get_channel_id().get_platform());
    TEST_ASSERT_EQUAL_STRING("12345", message.get_channel_id().get_id().c_str());

    TEST_ASSERT_FALSE(message.get_updates().isNull());
    TEST_ASSERT_FALSE(message.get_updates()["field1"].isNull());
    TEST_ASSERT_EQUAL(13, message.get_updates()["field1"].as<int>());
    TEST_ASSERT_FALSE(message.get_updates()["field2"].isNull());
    TEST_ASSERT_EQUAL_STRING("new_value", message.get_updates()["field2"].as<String>().c_str());
}

void test_channel_info_changed_message() {
    RUN_TEST(test_channel_info_changed_message_generate);
}