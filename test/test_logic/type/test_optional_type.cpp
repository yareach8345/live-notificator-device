//
// Created by yareach on 25. 8. 16..
//

#include <unity.h>
#include <sstream>
#include "type/optional.h"
#include "type/byte.h"
#include "type/string.h"

template<typename T>
std::string generate_default_value_mismatch_message(const T expected, const T actual) {
    std::ostringstream msg;
    msg << "\n" << "default value mismatch when test optional";
    msg << "\n" << "expected : " << expected;
    msg << "\n" << "actual : " << actual;
    return msg.str();
}

template<typename T>
std::string generate_default_value_mismatch_message(const T expected, const T actual, const String type_name) {
    std::ostringstream msg;
    msg << std::endl;
    msg << "default value mismatch when test optional<" + type_name + ">" << std::endl;
    msg << "expected : " << expected << std::endl;
    msg << "actual : " << actual << std::endl;
    return msg.str();
}

void test_null() {
    const optional<int> opt = optional<int>();

    TEST_ASSERT_EQUAL(optional<int>::get_default(), opt.get_value_unsafe());
    TEST_ASSERT_EQUAL(optional<int>::get_default(), opt.get_value_or_default());
    TEST_ASSERT_EQUAL(true, opt.is_empty());

    try {
        const int a = opt.get_value();
        TEST_FAIL_MESSAGE("Unexpected success when get_value from null");
    } catch (const CanNotReadFromOptionalError &err) {
        TEST_ASSERT_EQUAL_STRING("optional로 부터 값을 읽어올 수 없습니다. optional이 null값을 가지고 있습니다.", err.what());
    }
}

void test_get_value() {
    const optional<int> int_optional = optional<int>(42);

    TEST_ASSERT_EQUAL(42, int_optional.get_value());
    TEST_ASSERT_EQUAL(42, int_optional.get_value_or_default());
    TEST_ASSERT_EQUAL(false, int_optional.is_empty());
}

void test_optional_create() {
    const optional<byte> byte_optional = optional<byte>::create(42);
    TEST_ASSERT_EQUAL(42, byte_optional.get_value());
    TEST_ASSERT_EQUAL(42, byte_optional.get_value_or_default());
    TEST_ASSERT_EQUAL(false, byte_optional.is_empty());
}

void test_null_generate() {
    const optional<int> null_optional = optional<int>::get_null();

    TEST_ASSERT_EQUAL(true, null_optional.is_empty());

    TEST_ASSERT_EQUAL_MESSAGE(0, null_optional.get_value_unsafe(), generate_default_value_mismatch_message(0, null_optional.get_value_unsafe(), "int").c_str());
}

void test_default_values() {
    const optional<int> int_optional = optional<int>::get_null();
    const optional<byte> byte_optional = optional<byte>::get_null();
    const optional<bool> bool_optional = optional<bool>::get_null();
    const optional<String> string_optional = optional<String>::get_null();

    TEST_ASSERT_EQUAL_MESSAGE(0, int_optional.get_value_unsafe(), generate_default_value_mismatch_message(0, int_optional.get_value_unsafe(), "int").c_str());
    TEST_ASSERT_EQUAL_MESSAGE(0, byte_optional.get_value_unsafe(), generate_default_value_mismatch_message<int>(0, byte_optional.get_value_unsafe(), "byte").c_str());
    TEST_ASSERT_EQUAL_MESSAGE(false, bool_optional.get_value_unsafe(), generate_default_value_mismatch_message(false, bool_optional.get_value_unsafe(), "bool").c_str());
    TEST_ASSERT_EQUAL_STRING_MESSAGE("", string_optional.get_value_unsafe().c_str(), generate_default_value_mismatch_message<String>("\"\" (an empty string)", string_optional.get_value_unsafe(), "String").c_str());
}

void test_set_value() {
    optional<int> int_optional = optional<int>(1);

    const optional<int> before_set = int_optional;
    int_optional.set_value(2);
    const optional<int> after_set = int_optional;

    TEST_ASSERT_EQUAL(1, before_set.get_value());
    TEST_ASSERT_EQUAL(false, before_set.is_empty());
    TEST_ASSERT_EQUAL(2, after_set.get_value());
    TEST_ASSERT_EQUAL(false, after_set.is_empty());
}

void test_set_value_from_null() {
    optional<int> int_optional = optional<int>::get_null();

    const optional<int> before_set = int_optional;

    int_optional.set_value(1);
    const optional<int> after_set = int_optional;

    TEST_ASSERT_EQUAL(optional<int>::get_default(), before_set.get_value_unsafe());
    TEST_ASSERT_EQUAL(optional<int>::get_default(), before_set.get_value_or_default());
    TEST_ASSERT_EQUAL(true, before_set.is_empty());
    TEST_ASSERT_EQUAL(1, after_set.get_value());
    TEST_ASSERT_EQUAL(false, after_set.is_empty());
}

void test_set_value_to_null() {
    optional<int> int_optional = optional<int>(1);

    const optional<int> before_set = int_optional;

    int_optional.set_value_to_null();
    const optional<int> after_set = int_optional;

    TEST_ASSERT_EQUAL(1, before_set.get_value());
    TEST_ASSERT_EQUAL(1, before_set.get_value_or_default());
    TEST_ASSERT_EQUAL(false, before_set.is_empty());
    TEST_ASSERT_EQUAL(true, after_set.is_empty());
    TEST_ASSERT_EQUAL(optional<int>::get_default(), after_set.get_value_or_default());
}

void test_optional_type() {
    RUN_TEST(test_null);
    RUN_TEST(test_get_value);
    RUN_TEST(test_optional_create);
    RUN_TEST(test_null_generate);
    RUN_TEST(test_default_values);
    RUN_TEST(test_set_value);
    RUN_TEST(test_set_value_from_null);
    RUN_TEST(test_set_value_to_null);
}