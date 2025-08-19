//
// Created by yareach on 25. 8. 18..
//

#include <unity.h>
#include "mqtt/message/updated_message.h"
#include "mqtt/message_type.h"

void test_updated_message_generate() {
    const UpdatedMessage message;

    TEST_ASSERT_EQUAL(MessageType::UPDATED, message.get_message_type());
}

void test_updated_message() {
    RUN_TEST(test_updated_message_generate);
}