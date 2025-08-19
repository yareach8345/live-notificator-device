//
// Created by yareach on 25. 8. 18..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_MQTT_MESSAGE_H
#define LIVE_NOTIFICATOR_DEVICE_MQTT_MESSAGE_H

#include "../message_type.h"

class MessageBase {
public:
    virtual ~MessageBase() = default;

    virtual MessageType get_message_type() const = 0;
};

#endif //LIVE_NOTIFICATOR_DEVICE_MQTT_MESSAGE_H