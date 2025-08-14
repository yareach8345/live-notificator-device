//
// Created by yareach on 25. 8. 14..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_PARSING_ERROR_H
#define LIVE_NOTIFICATOR_DEVICE_PARSING_ERROR_H
#include <stdexcept>
#include "type/string.h"

class JsonParsingFailError : public std::runtime_error {
public:
    JsonParsingFailError(const String& message) : runtime_error(message.c_str()) {};
};

#endif //LIVE_NOTIFICATOR_DEVICE_PARSING_ERROR_H