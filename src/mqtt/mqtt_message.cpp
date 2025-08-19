//
// Created by yareach on 25. 8. 19..
//

#include "mqtt/mqtt_message.h"

MqttMessage::MqttMessage(const String &topic, const String &payload): topic(topic), payload(payload) {}

MqttMessage::MqttMessage(const char *topic, const byte *payload) {
    this->topic = topic;

    this->payload = String((char*)payload);
}

MqttMessage::MqttMessage(const char *topic, const byte *payload, const unsigned long length) {
    this->topic = topic;

    String payload_str = "";

    for (unsigned long i = 0; i <= length; i++) {
        payload_str += static_cast<char>(payload[i]);
    }

    this->payload = payload_str;
}


String MqttMessage::get_topic() const {
    return topic;
}

String MqttMessage::get_payload() const {
    return payload;
}