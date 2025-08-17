//
// Created by yareach on 25. 8. 14..
//

#include <unity.h>
#include "ArduinoJson.h"
#include "channel/live_close.h"
#include "type/string.h"
#include "json/util.h"
#include "channel/parser.h"

const String live_open_compact_json = "{\"channelId\":{\"id\":\"8c341b627588590585f269e69778ec93\",\"platform\":\"chzzk\"},\"detail\":{\"displayName\":\"스트리머1\",\"followerCount\":959,\"priority\":null,\"color\":\"#e7ebee\"},\"liveState\":{\"isOpen\":true,\"liveTitle\":\"test live title\",\"concurrentUserCount\":123,\"category\":\"test\"}}";

const String live_close_compact_json = "{\"channelId\":{\"id\":\"e7712b74723f253ad64457ba11962a08\",\"platform\":\"chzzk\"},\"detail\":{\"displayName\":\"스트리머2\",\"followerCount\":1524,\"priority\":2,\"color\":\"#e5a6ec\"},\"liveState\":{\"isOpen\":false}}";

void test_parse_json() {
    JsonDocument doc = parse_json_string(live_open_compact_json);

    TEST_ASSERT_FALSE(doc["channelId"].isNull());
    TEST_ASSERT_FALSE(doc["detail"].isNull());
    TEST_ASSERT_FALSE(doc["liveState"].isNull());
}

void test_parse_live_close() {
    JsonDocument doc = parse_json_string(live_close_compact_json);
    const JsonObjectConst live_state_object = doc["liveState"].as<JsonObjectConst>();

    const LiveClose live_close = parse_live_close(live_state_object);

    TEST_ASSERT_EQUAL(false, live_close.get_is_open());
}

void test_parse_live_open() {
    JsonDocument doc = parse_json_string(live_open_compact_json);
    const JsonObjectConst live_state_object = doc["liveState"].as<JsonObjectConst>();

    const LiveOpen live_open = parse_live_open(live_state_object);

    TEST_ASSERT_EQUAL(true, live_open.get_is_open());
    TEST_ASSERT_EQUAL(123, live_open.get_concurrent_user_count());
    TEST_ASSERT_EQUAL_STRING("test live title", live_open.get_live_title().c_str());
    TEST_ASSERT_EQUAL_STRING("test", live_open.get_category().c_str());
}

void test_parse_live_state() {
    JsonDocument live_close_doc = parse_json_string(live_close_compact_json);
    JsonDocument live_open_doc = parse_json_string(live_open_compact_json);

    const LiveStateVariant live_close = parse_live_state_from_json(live_close_doc["liveState"].as<JsonObjectConst>());
    const LiveStateVariant live_open = parse_live_state_from_json(live_open_doc["liveState"].as<JsonObjectConst>());

    TEST_ASSERT_EQUAL(OPEN, live_open.get_live_state_type());
    TEST_ASSERT_EQUAL(true, live_open.is_open());
    TEST_ASSERT_EQUAL(CLOSE, live_close.get_live_state_type());
    TEST_ASSERT_EQUAL(false, live_close.is_open());
}

void test_parsing_live_state_without_is_open_field() {
    const String json = "{\"liveTitle\":\"test\"}";
    JsonDocument doc = parse_json_string(json);

    try {
        parse_live_state_from_json(doc.as<JsonObjectConst>());
        TEST_FAIL_MESSAGE("실패해야할 실행 성공함");
    } catch (std::exception& e) {
        TEST_ASSERT_EQUAL_STRING("LiveState 파싱 에러. isOpen을 찾을 수 없음.", e.what());
    }
}

void test_parsing_live_close_without_required_field() {
    const String json = "{}";
    JsonDocument doc = parse_json_string(json);

    try {
        parse_live_close(doc.as<JsonObjectConst>());
        TEST_FAIL_MESSAGE("실패해야할 실행 성공함");
    } catch (std::exception& e) {
        TEST_ASSERT_EQUAL_STRING("파싱 에러 [LiveClose]: 필드 'isOpen' 없음", e.what());
    }
}

void test_parsing_live_open_without_required_field() {
    //시청자 수가 빠진 JSON
    const String json = "{\"isOpen\":true,\"liveTitle\":\"test live title\",\"category\":\"test\"}";
    JsonDocument doc = parse_json_string(json);

    try {
        parse_live_open(doc.as<JsonObjectConst>());
        TEST_FAIL_MESSAGE("실패해야할 실행 성공함");
    } catch (std::exception& e) {
        TEST_ASSERT_EQUAL_STRING("파싱 에러 [LiveOpen]: 필드 'concurrentUserCount' 없음", e.what());
    }
}

void test_live_state_parsing() {
    RUN_TEST(test_parse_json);
    RUN_TEST(test_parse_live_close);
    RUN_TEST(test_parse_live_open);
    RUN_TEST(test_parse_live_state);
    RUN_TEST(test_parsing_live_state_without_is_open_field);
    RUN_TEST(test_parsing_live_close_without_required_field);
    RUN_TEST(test_parsing_live_open_without_required_field);
}