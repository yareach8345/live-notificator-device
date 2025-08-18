//
// Created by yareach on 25. 8. 18..
//

#include "mqtt/message/channel_image_changed_message.h"

ChannelImageChangedMessage::ChannelImageChangedMessage(const ChannelId &channel_id) : channel_id(channel_id) {}

ChannelId ChannelImageChangedMessage::get_channel_id() const {
    return channel_id;
}

MessageType ChannelImageChangedMessage::get_message_type() const {
    return IMAGE_CHANGED;
}
