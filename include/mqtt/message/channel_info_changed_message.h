//
// Created by yareach on 25. 8. 18..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_CHANGED_MESSAGE_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_CHANGED_MESSAGE_H

#include "type/string.h"
#include "mqtt_message.h"
#include "ArduinoJson.h"
#include "channel/channel_id.h"

class ChannelInfoChangedMessage final : MqttMessage {
private:
    const ChannelId channel_id;
    const JsonObjectConst updates;
public:
    ChannelInfoChangedMessage(const ChannelId& channel_id, const JsonObjectConst& updates);

    MessageType get_message_type() const override;

    ChannelId get_channel_id() const;

    JsonObjectConst get_updates() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_CHANGED_MESSAGE_H