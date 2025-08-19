//
// Created by yareach on 25. 8. 19..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_MQTT_MESSAGE_H
#define LIVE_NOTIFICATOR_DEVICE_MQTT_MESSAGE_H

#include "type/string.h"
#include "type/byte.h"

class MqttMessage {
private:
    String topic;
    String payload;
public:
    MqttMessage(const String &topic, const String &payload);

    MqttMessage(const char *topic, const byte *payload);

    MqttMessage(const char *topic, const byte *payload, const unsigned long length);

    String get_topic() const;

    String get_payload() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_MQTT_MESSAGE_H