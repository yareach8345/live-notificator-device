//
// Created by yareach on 25. 8. 18..
//

#include "mqtt/message/channel_info_changed_message.h"

ChannelInfoChangedMessage::ChannelInfoChangedMessage(const ChannelId &channel_id, const JsonObjectConst &updates): channel_id(channel_id), updates(updates) {}

ChannelId ChannelInfoChangedMessage::get_channel_id() const {
    return channel_id;
}

JsonObjectConst ChannelInfoChangedMessage::get_updates() const {
    return updates;
}

MessageType ChannelInfoChangedMessage::get_message_type() const {
    return INFO_CHANGED;
}

