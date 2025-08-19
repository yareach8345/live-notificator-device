//
// Created by yareach on 25. 8. 19..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_BAD_TOPIC_ERROR_H
#define LIVE_NOTIFICATOR_DEVICE_BAD_TOPIC_ERROR_H
#include <stdexcept>
#include "type/string.h"

class BadTopicError final : public std::runtime_error {
public:
    explicit BadTopicError(const String& message) : runtime_error(message.c_str()) {};
};

#endif //LIVE_NOTIFICATOR_DEVICE_BAD_TOPIC_ERROR_H