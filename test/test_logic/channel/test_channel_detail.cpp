//
// Created by yareach on 25. 8. 17..
//

#include <unity.h>
#include "channel/channel_detail.h"

const ChannelDetail channel_detail("test_name", 13, optional<uint8_t>(1), optional<String>("#ffffff"));

void test_channel_get_value() {
    const ChannelDetail det = channel_detail;

    TEST_ASSERT_EQUAL_STRING("test_name", det.get_display_name().c_str());
    TEST_ASSERT_EQUAL(13, det.get_follower_count());
    TEST_ASSERT_FALSE(det.is_color_empty());
    TEST_ASSERT_EQUAL(1, det.get_priority().get_value());
    TEST_ASSERT_FALSE(det.is_priority_empty());
    TEST_ASSERT_EQUAL_STRING("#ffffff", det.get_color().get_value().c_str());
}

void test_channel_set_value() {
    ChannelDetail det = channel_detail;

    const ChannelDetail before_change = det;

    det.set_display_name("changed_name");
    det.set_follower_count(10);
    det.set_priority(2);
    det.set_color("#000000");

    TEST_ASSERT_EQUAL_STRING("test_name", before_change.get_display_name().c_str());
    TEST_ASSERT_EQUAL_STRING("changed_name", det.get_display_name().c_str());
    TEST_ASSERT_EQUAL(13, before_change.get_follower_count());
    TEST_ASSERT_EQUAL(10, det.get_follower_count());
    TEST_ASSERT_EQUAL(1, before_change.get_priority().get_value());
    TEST_ASSERT_EQUAL(2, det.get_priority().get_value());
    TEST_ASSERT_EQUAL_STRING("#ffffff", before_change.get_color().get_value().c_str());
    TEST_ASSERT_EQUAL_STRING("#000000", det.get_color().get_value().c_str());
}

void test_set_optional_value_to_null() {
    ChannelDetail det = channel_detail;

    det.set_color_to_null();
    det.set_priority_to_null();

    TEST_ASSERT_TRUE(det.get_priority().is_empty());

    TEST_ASSERT_TRUE(det.get_color().is_empty());
}

void test_is_optional_value_empty() {

    ChannelDetail det = channel_detail;

    const ChannelDetail before_change = det;

    det.set_color_to_null();
    det.set_priority_to_null();

    TEST_ASSERT_FALSE(before_change.is_priority_empty());
    TEST_ASSERT_TRUE(det.is_priority_empty());

    TEST_ASSERT_FALSE(before_change.is_color_empty());
    TEST_ASSERT_TRUE(det.is_color_empty());
}

void test_channel_detail() {
    RUN_TEST(test_channel_get_value);
    RUN_TEST(test_channel_set_value);
    RUN_TEST(test_set_optional_value_to_null);
    RUN_TEST(test_is_optional_value_empty);
}