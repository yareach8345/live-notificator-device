//
// Created by yareach on 25. 8. 19..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_TOPIC_H
#define LIVE_NOTIFICATOR_DEVICE_TOPIC_H

#include "message_type.h"
#include "type/string.h"

MessageType get_message_type_from_topic(const String& topic);

#endif //LIVE_NOTIFICATOR_DEVICE_TOPIC_H