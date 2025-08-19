//
// Created by yareach on 25. 8. 19..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_MESSAGE_BASE_H
#define LIVE_NOTIFICATOR_DEVICE_MESSAGE_BASE_H

#include "../message_type.h"

class MessageBase {
public:
    virtual ~MessageBase() = default;

    virtual MessageType get_message_type() const = 0;
};

#endif //LIVE_NOTIFICATOR_DEVICE_MESSAGE_BASE_H