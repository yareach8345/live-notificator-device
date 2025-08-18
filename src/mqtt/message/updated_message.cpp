//
// Created by yareach on 25. 8. 18..
//

#include "mqtt/message/updated_message.h"

MessageType UpdatedMessage::get_message_type() const {
    return UPDATED;
}