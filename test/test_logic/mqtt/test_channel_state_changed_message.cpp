//
// Created by yareach on 25. 8. 18..
//

#include <unity.h>
#include "mqtt/message/channel_state_changed_message.h"

void test_channel_state_changed_message_generate() {
    const ChannelStateChangedMessage message( ChannelId(CHZZK, "12345"), OPEN);

    TEST_ASSERT_EQUAL(CHZZK, message.get_channel_id().get_platform());
    TEST_ASSERT_EQUAL_STRING("12345", message.get_channel_id().get_id().c_str());
    TEST_ASSERT_EQUAL(OPEN, message.get_new_state());
}

void test_channel_state_changed_message() {
    RUN_TEST(test_channel_state_changed_message_generate);
}