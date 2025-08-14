//
// Created by yareach on 25. 8. 14..
//

#include "util/json.h"

JsonDocument parse_json_string(const String &json) {
    JsonDocument doc;
    deserializeJson(doc, json);

    return doc;
}