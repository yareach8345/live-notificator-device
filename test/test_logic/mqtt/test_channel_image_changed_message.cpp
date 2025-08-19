//
// Created by yareach on 25. 8. 18..
//

#include <unity.h>
#include "mqtt/message/channel_image_changed_message.h"

void test_channel_image_changed_message_generate() {
    const ChannelImageChangedMessage message(ChannelId(YOUTUBE, "test"));

    TEST_ASSERT_EQUAL(YOUTUBE, message.get_channel_id().get_platform());
    TEST_ASSERT_EQUAL_STRING("test", message.get_channel_id().get_id().c_str());
}

void test_channel_image_changed_message() {
    RUN_TEST(test_channel_image_changed_message_generate);
}