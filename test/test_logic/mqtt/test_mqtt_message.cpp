//
// Created by yareach on 25. 8. 19..
//

#include <unity.h>
#include "type/string.h"
#include "type/byte.h"
#include "mqtt/mqtt_message.h"

void test_mqtt_message_gen_with_string() {
    const String topic = "test/topic";
    const String payload = "test payload";

    const MqttMessage message(topic, payload);

    TEST_ASSERT_EQUAL_STRING("test/topic", message.get_topic().c_str());
    TEST_ASSERT_EQUAL_STRING("test payload", message.get_payload().c_str());
}

void test_mqtt_message_gen_with_char_pointer_and_byte_pointer() {
    const char *topic = "test/topic";
    const char *payload = "test payload";

    byte payload_byte[13] = {};

    for (size_t i = 0; i < 13; i++) {
        payload_byte[i] = static_cast<byte>(payload[i]);
    }

    const MqttMessage message(topic, payload_byte);

    TEST_ASSERT_EQUAL_STRING("test/topic", message.get_topic().c_str());
    TEST_ASSERT_EQUAL_STRING("test payload", message.get_payload().c_str());
}

void test_mqtt_message_gen_with_char_pointer_and_byte_pointer_and_length() {
    const char *topic = "test/topic";
    const char *payload = "test payload";

    byte payload_byte[13] = {};

    for (size_t i = 0; i < 13; i++) {
        payload_byte[i] = static_cast<byte>(payload[i]);
    }

    const MqttMessage message(topic, payload_byte, 13);

    TEST_ASSERT_EQUAL_STRING("test/topic", message.get_topic().c_str());
    TEST_ASSERT_EQUAL_STRING("test payload", message.get_payload().c_str());
}

void test_mqtt_message() {
    RUN_TEST(test_mqtt_message_gen_with_string);
    RUN_TEST(test_mqtt_message_gen_with_char_pointer_and_byte_pointer);
    RUN_TEST(test_mqtt_message_gen_with_char_pointer_and_byte_pointer_and_length);
}