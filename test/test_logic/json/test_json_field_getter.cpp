//
// Created by yareach on 25. 8. 14..
//

#include <unity.h>

#include "error/json_parsing_fail_error.h"
#include "json/json_field_getter.h"
#include "json/util.h"
#include "type/string.h"

const String json_string = "{\"field1\":\"value1\",\"field2\":23,\"field3\":true}";

const JsonDocument json = parse_json_string(json_string);

void test_get_field() {
    const JsonFieldGetter field_getter("json", json.as<JsonObjectConst>());

    //can read value
    const JsonVariantConst field1 = field_getter.get_field("field1");
    const JsonVariantConst field2 = field_getter.get_field("field2");
    const JsonVariantConst field3 = field_getter.get_field("field3");

    // //can read null value
    const JsonVariantConst null_value = field_getter.get_field("null_value");

    TEST_ASSERT_EQUAL_STRING("value1", field1.as<String>().c_str());
    TEST_ASSERT_EQUAL(23, field2.as<int>());
    TEST_ASSERT_EQUAL(true, field3.as<bool>());

    TEST_ASSERT_EQUAL(true, null_value.isNull());
}

void test_get_required_field() {
    const JsonFieldGetter field_getter("json", json.as<JsonObjectConst>());

    const JsonVariantConst field1 = field_getter.get_required_field("field1");
    TEST_ASSERT_EQUAL_STRING("value1", field1.as<String>().c_str());

    // 필드 존재x시 에러 발생 검증
    try {
        const JsonVariantConst null_value = field_getter.get_required_field("null_value");
        TEST_FAIL_MESSAGE("예외가 발생하지 않음");
    } catch (const JsonParsingFailError& error) {
        TEST_ASSERT_EQUAL_STRING("파싱 에러 [json]: 필드 'null_value' 없음", error.what());
    }
}

void test_json_field_getter() {
    RUN_TEST(test_get_field);
    RUN_TEST(test_get_required_field);
}