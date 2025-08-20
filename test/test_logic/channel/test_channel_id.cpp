//
// Created by yareach on 25. 8. 15..
//

#include <unity.h>

#include "ArduinoJson.h"
#include "channel/parser.h"
#include "error/parsing_fail_error.h"
#include "json/util.h"

void test_parse_chzzk_channel_id() {
    const String json = "{\"platform\":\"chzzk\",\"id\":\"1234\"}";
    JsonDocument doc = parse_json_string(json);

    const ChannelId parse_result = parse_channel_id(doc.as<JsonObjectConst>());

    TEST_ASSERT_EQUAL(Platform::CHZZK, parse_result.get_platform());
    TEST_ASSERT_EQUAL_STRING("1234", parse_result.get_id().c_str());
}

void test_parse_youtube_channel_id() {
    const String json = "{\"platform\":\"youtube\",\"id\":\"abc123\"}";
    JsonDocument doc = parse_json_string(json);

    const ChannelId parse_result = parse_channel_id(doc.as<JsonObjectConst>());

    TEST_ASSERT_EQUAL(Platform::YOUTUBE, parse_result.get_platform());
    TEST_ASSERT_EQUAL_STRING("abc123", parse_result.get_id().c_str());
}

void try_parse_with_unknown_platform() {
    const String json = "{\"platform\":\"unknown\",\"id\":\"abc123\"}";
    JsonDocument doc = parse_json_string(json);

    try {
        const ChannelId parse_result = parse_channel_id(doc.as<JsonObjectConst>());
        TEST_FAIL_MESSAGE("Unexpected success");
    } catch (const ParsingFailError& error) {
        TEST_ASSERT_EQUAL_STRING("Platform 파싱 실패. 문자열 'unknown'는 Platform으로 파싱될 수 없습니다.", error.what());
    }
}

void test_channel_id() {
    RUN_TEST(test_parse_chzzk_channel_id);
    RUN_TEST(test_parse_youtube_channel_id);
    RUN_TEST(try_parse_with_unknown_platform);
}