//
// Created by yareach on 25. 8. 19..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_TOPIC_H
#define LIVE_NOTIFICATOR_DEVICE_TOPIC_H

#include "message_type.h"
#include "channel/channel_id.h"
#include "type/string.h"

MessageType get_message_type_from_topic(const String& topic);

ChannelId get_channel_id_from_topic(const String& topic);

#endif //LIVE_NOTIFICATOR_DEVICE_TOPIC_H