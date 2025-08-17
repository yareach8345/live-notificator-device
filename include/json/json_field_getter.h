//
// Created by yareach on 25. 8. 14..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_JSON_FIELD_GETTER_H
#define LIVE_NOTIFICATOR_DEVICE_JSON_FIELD_GETTER_H

#include <ArduinoJson.h>
#include "type/string.h"
#include "type/optional.h"

class JsonFieldGetter {
private:
    const JsonObjectConst &json_object;
    const String context;
public:
    JsonFieldGetter(const String &context, const JsonObjectConst &obj): json_object(obj), context(context) {}

    JsonVariantConst get_field(const String &field_name) const;

    JsonVariantConst get_required_field(const String &field_name) const;

    template<typename T>
    optional<T> get_field_optional(const String &field_name) const {
        const JsonVariantConst value = get_field(field_name);
        if (value.isNull()) {
            return optional<T>::get_null();
        } else {
            return optional<T>(value.as<T>());
        }
    }
};

#endif //LIVE_NOTIFICATOR_DEVICE_JSON_FIELD_GETTER_H