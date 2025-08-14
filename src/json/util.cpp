//
// Created by yareach on 25. 8. 14..
//

#include <functional>
#include "type/string.h"
#include "json/util.h"
#include "error/json_parsing_fail_error.h"

JsonDocument parse_json_string(const String &json) {
    JsonDocument doc;
    deserializeJson(doc, json);

    return doc;
}

std::function<JsonVariantConst(const String&)> make_get_required_field(const String &context, const JsonObjectConst& obj) {
    return [&context, &obj](const String &field_name) {
        const JsonVariantConst field = obj[field_name];
        if (field.isNull()) {
            throw JsonParsingFailError("파싱 에러 [" + context + "]: 필드 '" + field_name + "' 없음");
        }
        return field;
    };
}
