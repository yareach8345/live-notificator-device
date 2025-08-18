//
// Created by yareach on 25. 8. 17..
//

#include <unity.h>

#include "channel/channel_info.h"
#include "channel/live_close.h"
#include "channel/live_open.h"

void test_channel_info_gen() {
    const ChannelInfo ci(
        ChannelId(CHZZK, "123"),
        ChannelDetail("tester", 123, 12, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    TEST_ASSERT_EQUAL(CHZZK, ci.get_channel_id().get_platform());
    TEST_ASSERT_EQUAL_STRING("123", ci.get_channel_id().get_id().c_str());

    TEST_ASSERT_EQUAL_STRING("tester", ci.get_detail().get_display_name().c_str());
    TEST_ASSERT_EQUAL(123, ci.get_detail().get_follower_count());
    TEST_ASSERT_EQUAL(12, ci.get_detail().get_priority().get_value());
    TEST_ASSERT_EQUAL_STRING("#ffffff", ci.get_detail().get_color().get_value().c_str());

    TEST_ASSERT_EQUAL(CLOSE, ci.get_live_state_type());
}

void test_channel_info_change_with_ref() {
    ChannelInfo ci(
        ChannelId(CHZZK, "123"),
        ChannelDetail("tester", 123, 12, String("#ffffff")),
        std::make_shared<LiveOpen>("hello world", "test", 1)
    );

    const long before_user_count = static_cast<LiveOpen*>(ci.get_live_state().get())->get_concurrent_user_count();
    static_cast<LiveOpen*>(ci.get_live_state().get())->set_concurrent_user_count(100);
    const long after_user_count = static_cast<LiveOpen*>(ci.get_live_state().get())->get_concurrent_user_count();

    const String before_display_name = ci.get_detail().get_display_name();
    ci.get_detail_ref()->set_display_name("test boy");
    const String after_display_name = ci.get_detail().get_display_name();

    TEST_ASSERT_EQUAL_STRING("tester", before_display_name.c_str());
    TEST_ASSERT_EQUAL_STRING("test boy", after_display_name.c_str());

    TEST_ASSERT_EQUAL(1, before_user_count);
    TEST_ASSERT_EQUAL(100, after_user_count);
}

void test_channel_info_live_state_change() {
    ChannelInfo ci(
        ChannelId(CHZZK, "123"),
        ChannelDetail("tester", 123, 12, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    const LiveStateType live_state_type_before = ci.get_live_state_type();
    ci.set_live_state(std::make_shared<LiveOpen>("testing", "test", 12));

    const LiveStateType live_state_type_after = ci.get_live_state_type();

    TEST_ASSERT_EQUAL(CLOSE, live_state_type_before);
    TEST_ASSERT_EQUAL(OPEN, live_state_type_after);
}

void test_channel_info() {
    RUN_TEST(test_channel_info_gen);
    RUN_TEST(test_channel_info_change_with_ref);
    RUN_TEST(test_channel_info_live_state_change);
}