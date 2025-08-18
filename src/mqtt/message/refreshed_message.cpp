//
// Created by yareach on 25. 8. 18..
//

#include "mqtt/message/refreshed_message.h"

MessageType RefreshedMessage::get_message_type() const {
    return MessageType::REFRESHED;
}