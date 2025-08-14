//
// Created by yareach on 25. 8. 14..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_JSON_FIELD_GETTER_H
#define LIVE_NOTIFICATOR_DEVICE_JSON_FIELD_GETTER_H

#include <ArduinoJson.h>
#include "type/string.h"

class JsonFieldGetter {
private:
    const JsonObjectConst &json_object;
    const String &context;
public:
    JsonFieldGetter(const String &context, const JsonObjectConst &obj): json_object(obj), context(context) {}

    const JsonVariantConst get_field(const String &field_name) const;

    const JsonVariantConst get_required_field(const String &field_name) const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_JSON_FIELD_GETTER_H