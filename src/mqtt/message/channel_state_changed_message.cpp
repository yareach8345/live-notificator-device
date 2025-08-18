//
// Created by yareach on 25. 8. 18..
//

#include "mqtt/message/channel_state_changed_message.h"

ChannelStateChangedMessage::ChannelStateChangedMessage(const ChannelId &channel_id, const String &new_state) : channel_id(channel_id), new_state(new_state) {}

ChannelId ChannelStateChangedMessage::get_channel_id() const {
    return channel_id;
}

String ChannelStateChangedMessage::get_new_state() const {
    return new_state;
}

MessageType ChannelStateChangedMessage::get_message_type() const {
    return STATE_CHANGED;
}

