//
// Created by yareach on 25. 8. 18..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_STATE_CHANGED_MESSAGE_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_STATE_CHANGED_MESSAGE_H

#include "type/string.h"
#include "mqtt_message.h"
#include "channel/channel_id.h"
#include "../channel_state.h"

class ChannelStateChangedMessage final : public MqttMessage {
private:
    const ChannelId channel_id;
    const ChannelState new_state;
public:
    ChannelStateChangedMessage(const ChannelId& channel_id, const ChannelState new_state);

    MessageType get_message_type() const override;

    ChannelId get_channel_id() const;

    ChannelState get_new_state() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_STATE_CHANGED_MESSAGE_H