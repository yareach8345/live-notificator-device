//
// Created by yareach on 25. 8. 14..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_JSON_H
#define LIVE_NOTIFICATOR_DEVICE_JSON_H

#include "type/string.h"
#include "ArduinoJson.h"

JsonDocument parse_json_string(const String &json);

#endif //LIVE_NOTIFICATOR_DEVICE_JSON_H