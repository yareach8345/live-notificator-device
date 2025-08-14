//
// Created by yareach on 25. 8. 14..
//

#include "json/json_field_getter.h"
#include "error/json_parsing_fail_error.h"
#include "type/string.h"

const JsonVariantConst JsonFieldGetter::get_field(const String &field_name) const {
    return json_object[field_name];
}

const JsonVariantConst JsonFieldGetter::get_required_field(const String &field_name) const {
    const JsonVariantConst field = json_object[field_name];
    if (field.isNull()) {
        throw JsonParsingFailError("파싱 에러 [" + context + "]: 필드 '" + field_name + "' 없음");
    }

    return field;
}

