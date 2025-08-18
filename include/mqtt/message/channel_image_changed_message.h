//
// Created by yareach on 25. 8. 18..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_IMAGE_CHANGED_MESSAGE_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_IMAGE_CHANGED_MESSAGE_H
#include "mqtt_message.h"
#include "channel/channel_id.h"

class ChannelImageChangedMessage final : public MqttMessage {
private:
    ChannelId channel_id;
public:
    ChannelImageChangedMessage(const ChannelId& channel_id);

    ChannelId get_channel_id() const;

    MessageType get_message_type() const override;
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_IMAGE_CHANGED_MESSAGE_H