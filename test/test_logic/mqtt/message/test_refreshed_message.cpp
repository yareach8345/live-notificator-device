//
// Created by yareach on 25. 8. 18..
//

#include <unity.h>
#include "mqtt/message/refreshed_message.h"

void test_refreshed_message_generate() {
    const RefreshedMessage message;

    TEST_ASSERT_EQUAL(MessageType::REFRESHED, message.get_message_type());
}

void test_refreshed_message() {
    RUN_TEST(test_refreshed_message_generate);
}