//
// Created by yareach on 25. 8. 17..
//

#include <unity.h>

#include "type/string.h"
#include "channel/parser.h"
#include "json/util.h"

const String live_open_compact_json = "{\"channelId\":{\"id\":\"8c341b627588590585f269e69778ec93\",\"platform\":\"chzzk\"},\"detail\":{\"displayName\":\"스트리머1\",\"followerCount\":959,\"priority\":null,\"color\":\"#e7ebee\"},\"liveState\":{\"isOpen\":true,\"liveTitle\":\"test live title\",\"concurrentUserCount\":123,\"category\":\"test\"}}";
const String live_close_compact_json = "{\"channelId\":{\"id\":\"vEsDwh9jsLs\",\"platform\":\"youtube\"},\"detail\":{\"displayName\":\"스트리머2\",\"followerCount\":1524,\"priority\":2,\"color\":null},\"liveState\":{\"isOpen\":false}}";

void test_close_channel_info_parsing() {
    JsonDocument doc = parse_json_string(live_close_compact_json);
    const ChannelInfo ci_close = parse_channel_info(doc.as<JsonObject>());

    const ChannelId channel_id = ci_close.get_channel_id();
    const ChannelDetail detail = ci_close.get_detail();
    const LiveStateType live_state_type = ci_close.get_live_state_type();
    const LiveClose close = ci_close.get_live_state_variant().get_live_state_by_close();

    TEST_ASSERT_EQUAL(YOUTUBE, channel_id.get_platform());
    TEST_ASSERT_EQUAL_STRING("vEsDwh9jsLs", channel_id.get_id().c_str());

    TEST_ASSERT_EQUAL_STRING("스트리머2", detail.get_display_name().c_str());
    TEST_ASSERT_EQUAL(1524, detail.get_follower_count());
    TEST_ASSERT_EQUAL(false, detail.get_priority().is_empty());
    TEST_ASSERT_EQUAL(2, detail.get_priority().get_value());
    TEST_ASSERT_EQUAL(true, detail.get_color().is_empty());

    TEST_ASSERT_EQUAL(CLOSE, live_state_type);
}

void test_open_channel_info_parsing() {
    JsonDocument doc = parse_json_string(live_open_compact_json);
    const ChannelInfo ci_open = parse_channel_info(doc.as<JsonObject>());

    const ChannelId channel_id = ci_open.get_channel_id();
    const ChannelDetail detail = ci_open.get_detail();
    const LiveStateType live_state_type = ci_open.get_live_state_type();
    const LiveOpen open = ci_open.get_live_state_variant().get_live_state_by_open();

    TEST_ASSERT_EQUAL(CHZZK, channel_id.get_platform());
    TEST_ASSERT_EQUAL_STRING("8c341b627588590585f269e69778ec93", channel_id.get_id().c_str());

    TEST_ASSERT_EQUAL_STRING("스트리머1", detail.get_display_name().c_str());
    TEST_ASSERT_EQUAL(959, detail.get_follower_count());
    TEST_ASSERT_EQUAL(true, detail.get_priority().is_empty());
    TEST_ASSERT_EQUAL(false, detail.get_color().is_empty());
    TEST_ASSERT_EQUAL_STRING("#e7ebee", detail.get_color().get_value().c_str());

    TEST_ASSERT_EQUAL(OPEN, live_state_type);
    TEST_ASSERT_EQUAL(true, open.get_is_open());
    TEST_ASSERT_EQUAL_STRING("test live title", open.get_live_title().c_str());
    TEST_ASSERT_EQUAL(123, open.get_concurrent_user_count());
    TEST_ASSERT_EQUAL_STRING("test", open.get_category().c_str());
}

void test_channel_info_parsing() {
    RUN_TEST(test_close_channel_info_parsing);
    RUN_TEST(test_open_channel_info_parsing);
}
