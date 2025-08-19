//
// Created by yareach on 25. 8. 19..
//

#include <unity.h>

#include "string/util.h"

void split() {
    const String str = "test1,test2";

    const std::vector<String> result = split(str, ',');

    TEST_ASSERT_EQUAL(2, result.size());
    TEST_ASSERT_EQUAL_STRING("test1", result[0].c_str());
    TEST_ASSERT_EQUAL_STRING("test2", result[1].c_str());
}

void split_with_empty_string() {
    const String str = "";

    const std::vector<String> result = split(str, ',');

    TEST_ASSERT_EQUAL(0, result.size());
}

void split_with_only_one_element() {
    const String str = "test";

    const std::vector<String> result = split(str, ',');

    TEST_ASSERT_EQUAL(1, result.size());
    TEST_ASSERT_EQUAL_STRING("test", result[0].c_str());
}

void split_with_empty_element() {
    const String str = ",test1,,test2";

    const std::vector<String> result = split(str, ',');

    TEST_ASSERT_EQUAL(4, result.size());
    TEST_ASSERT_EQUAL_STRING("", result[0].c_str());
    TEST_ASSERT_EQUAL_STRING("test1", result[1].c_str());
    TEST_ASSERT_EQUAL_STRING("", result[2].c_str());
    TEST_ASSERT_EQUAL_STRING("test2", result[3].c_str());
}

void can_parse_topic_with_split() {
    const String topic = "service_name/topic1/topic2";

    const std::vector<String> result = split(topic, '/');

    TEST_ASSERT_EQUAL(3, result.size());
    TEST_ASSERT_EQUAL_STRING("service_name", result[0].c_str());
    TEST_ASSERT_EQUAL_STRING("topic1", result[1].c_str());
    TEST_ASSERT_EQUAL_STRING("topic2", result[2].c_str());
}

void test_split() {
    RUN_TEST(split);
    RUN_TEST(split_with_empty_string);
    RUN_TEST(split_with_only_one_element);
    RUN_TEST(split_with_empty_element);
    RUN_TEST(can_parse_topic_with_split);
}