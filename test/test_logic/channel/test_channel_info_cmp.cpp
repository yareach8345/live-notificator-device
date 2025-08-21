//
// Created by yareach on 25. 8. 20..
//

#include <unity.h>
#include "channel/channel_info_cmp.h"
#include "channel/parser.h"
#include "json/util.h"

ChannelInfoCmp cmp;

const String live_open_compact_json1 = "{\"channelId\":{\"id\":\"12345\",\"platform\":\"chzzk\"},\"detail\":{\"displayName\":\"스트리머1\",\"followerCount\":123,\"priority\":1,\"color\":\"#e7ebee\"},\"liveState\":{\"isOpen\":true,\"liveTitle\":\"test live title\",\"concurrentUserCount\":123,\"category\":\"test\"}}";
const String live_open_compact_json2 = "{\"channelId\":{\"id\":\"12345\",\"platform\":\"chzzk\"},\"detail\":{\"displayName\":\"스트리머1\",\"followerCount\":567,\"priority\":null,\"color\":\"#e7ebee\"},\"liveState\":{\"isOpen\":true,\"liveTitle\":\"test live title\",\"concurrentUserCount\":432,\"category\":\"test\"}}";
const String live_close_compact_json1 = "{\"channelId\":{\"id\":\"99999\",\"platform\":\"chzzk\"},\"detail\":{\"displayName\":\"스트리머2\",\"followerCount\":135,\"priority\":2,\"color\":null},\"liveState\":{\"isOpen\":false}}";
const String live_close_compact_json2 = "{\"channelId\":{\"id\":\"99999\",\"platform\":\"chzzk\"},\"detail\":{\"displayName\":\"스트리머2\",\"followerCount\":99999,\"priority\":3,\"color\":null},\"liveState\":{\"isOpen\":false}}";

#include "queue"
#include "memory"

void use_priority_queue_with_channel_info() {
    const ChannelInfo ch1(
        ChannelId(Platform::CHZZK, "1"),
        ChannelDetail("testing", 999, 1, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    const ChannelInfo ch2(
        ChannelId(Platform::CHZZK, "2"),
        ChannelDetail("testing", 123, 1, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    const ChannelInfo ch3(
        ChannelId(Platform::CHZZK, "3"),
        ChannelDetail("testing", 123, 2, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    const ChannelInfo ch4(
        ChannelId(Platform::CHZZK, "4"),
        ChannelDetail("testing", 123, 1, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    const ChannelInfo ch5(
        ChannelId(Platform::CHZZK, "5"),
        ChannelDetail("testing", 123, 2, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    const ChannelInfo ch6(
        ChannelId(Platform::CHZZK, "6"),
        ChannelDetail("testing", 1, 2, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    std::priority_queue<std::shared_ptr<ChannelInfo>, std::vector<std::shared_ptr<ChannelInfo>>, ChannelInfoCmp> pq;

    pq.push(std::make_shared<ChannelInfo>(ch5));
    pq.push(std::make_shared<ChannelInfo>(ch2));
    pq.push(std::make_shared<ChannelInfo>(ch4));
    pq.push(std::make_shared<ChannelInfo>(ch6));
    pq.push(std::make_shared<ChannelInfo>(ch3));
    pq.push(std::make_shared<ChannelInfo>(ch1));

    TEST_ASSERT_EQUAL_STRING("6", pq.top()->get_channel_id().get_id().c_str());
    pq.pop();
    TEST_ASSERT_EQUAL_STRING("5", pq.top()->get_channel_id().get_id().c_str());
    pq.pop();
    TEST_ASSERT_EQUAL_STRING("4", pq.top()->get_channel_id().get_id().c_str());
    pq.pop();
    TEST_ASSERT_EQUAL_STRING("3", pq.top()->get_channel_id().get_id().c_str());
    pq.pop();
    TEST_ASSERT_EQUAL_STRING("2", pq.top()->get_channel_id().get_id().c_str());
    pq.pop();
    TEST_ASSERT_EQUAL_STRING("1", pq.top()->get_channel_id().get_id().c_str());
    pq.pop();
}

void compare_with_is_open() {
    const ChannelInfo open_channel(
        ChannelId(Platform::CHZZK, "1"),
        ChannelDetail("testing", 123, 12, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    const ChannelInfo close_channel(
        ChannelId(Platform::CHZZK, "2"),
        ChannelDetail("testing", 123, 12, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    TEST_ASSERT_TRUE(ChannelInfoCmp::compare_with_is_open(open_channel, close_channel));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(close_channel, open_channel));

    TEST_ASSERT_TRUE(cmp(open_channel, close_channel));
    TEST_ASSERT_FALSE(cmp(close_channel, open_channel));

    TEST_ASSERT_TRUE(cmp(std::make_shared<ChannelInfo>(open_channel), std::make_shared<ChannelInfo>(close_channel)));
    TEST_ASSERT_FALSE(cmp(std::make_shared<ChannelInfo>(close_channel), std::make_shared<ChannelInfo>(open_channel)));
}

void compare_with_priority_when_one_channel_has_not_priority() {
    const ChannelInfo channel_priority_null(
        ChannelId(Platform::CHZZK, "3"),
        ChannelDetail("testing", 123, optional<byte>::get_null(), String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    const ChannelInfo channel_have_priority(
        ChannelId(Platform::CHZZK, "4"),
        ChannelDetail("testing", 123, 12, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    // 전제조건 : 둘의 is_open이 같아야 함
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(channel_priority_null, channel_have_priority));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(channel_have_priority, channel_priority_null));

    // 둘은 priority로 비교가능
    TEST_ASSERT_TRUE(ChannelInfoCmp::compare_with_priority(channel_have_priority, channel_priority_null));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_priority(channel_priority_null, channel_have_priority));

    // 둘의 라이브 상태가 같을 때, priority에 의해 결정됨
    TEST_ASSERT_TRUE(cmp(channel_have_priority, channel_priority_null));
    TEST_ASSERT_FALSE(cmp(channel_priority_null, channel_have_priority));

    // shared_ptr에서도 동일하게 작동
    TEST_ASSERT_TRUE(cmp(std::make_shared<ChannelInfo>(channel_have_priority), std::make_shared<ChannelInfo>(channel_priority_null)));
    TEST_ASSERT_FALSE(cmp(std::make_shared<ChannelInfo>(channel_priority_null), std::make_shared<ChannelInfo>(channel_have_priority)));
}

void compare_with_priority_when_both_channels_have_priority() {
    const ChannelInfo channel_have_higher_priority(
        ChannelId(Platform::CHZZK, "12345"),
        ChannelDetail("testing", 123, 1, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    const ChannelInfo channel_have_lower_priority(
        ChannelId(Platform::CHZZK, "99999"),
        ChannelDetail("testing", 123, 12, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    // 전제조건 : 둘의 is_open이 같아야 함
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(channel_have_higher_priority, channel_have_lower_priority));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(channel_have_lower_priority, channel_have_higher_priority));

    // 둘은 priority로 비교가능
    TEST_ASSERT_TRUE(ChannelInfoCmp::compare_with_priority(channel_have_higher_priority, channel_have_lower_priority));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_priority(channel_have_lower_priority, channel_have_higher_priority));

    // 둘의 라이브 상태가 같을 때, priority에 의해 결정됨
    TEST_ASSERT_TRUE(cmp(channel_have_higher_priority, channel_have_lower_priority));
    TEST_ASSERT_FALSE(cmp(channel_have_lower_priority, channel_have_higher_priority));

    // shared_ptr에서도 동일하게 작동
    TEST_ASSERT_TRUE(cmp(std::make_shared<ChannelInfo>(channel_have_higher_priority), std::make_shared<ChannelInfo>(channel_have_lower_priority)));
    TEST_ASSERT_FALSE(cmp(std::make_shared<ChannelInfo>(channel_have_lower_priority), std::make_shared<ChannelInfo>(channel_have_higher_priority)));
}

void compare_with_concurrent_user_count() {
    ChannelInfo channel_have_more_concurrent_user_count(
        ChannelId(Platform::CHZZK, "12345"),
        ChannelDetail("testing", 123, 12, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 999)
    );

    ChannelInfo channel_have_less_concurrent_user_count(
        ChannelId(Platform::CHZZK, "99999"),
        ChannelDetail("testing", 123, 12, String("#ffffff")),
        std::make_shared<LiveOpen>("test", "test", 12)
    );

    // 전제조건1 : 둘의 is_open이 같아야 함
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(channel_have_more_concurrent_user_count, channel_have_less_concurrent_user_count));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(channel_have_less_concurrent_user_count, channel_have_more_concurrent_user_count));

    // 전제조건2 : 둘의 priority가 같아야 함
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_priority(channel_have_more_concurrent_user_count, channel_have_less_concurrent_user_count));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_priority(channel_have_less_concurrent_user_count, channel_have_more_concurrent_user_count));

    // 전제조건3 : 둘의 is_open이 true
    TEST_ASSERT_TRUE(channel_have_more_concurrent_user_count.get_live_state()->get_is_open());
    TEST_ASSERT_TRUE(channel_have_less_concurrent_user_count.get_live_state()->get_is_open());

    // 둘의 concurrent user count로 비교가능
    TEST_ASSERT_TRUE(ChannelInfoCmp::compare_with_concurrent_user_count(channel_have_more_concurrent_user_count, channel_have_less_concurrent_user_count));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_concurrent_user_count(channel_have_less_concurrent_user_count, channel_have_more_concurrent_user_count));

    // 둘의 라이브 상태, 우선순위가 같을 때 concurrent user count로 결정됨
    TEST_ASSERT_TRUE(cmp(channel_have_more_concurrent_user_count, channel_have_less_concurrent_user_count));
    TEST_ASSERT_FALSE(cmp(channel_have_less_concurrent_user_count, channel_have_more_concurrent_user_count));

    // shared_ptr에서도 동일하게 작동
    TEST_ASSERT_TRUE(cmp(std::make_shared<ChannelInfo>(channel_have_more_concurrent_user_count), std::make_shared<ChannelInfo>(channel_have_less_concurrent_user_count)));
    TEST_ASSERT_FALSE(cmp(std::make_shared<ChannelInfo>(channel_have_less_concurrent_user_count), std::make_shared<ChannelInfo>(channel_have_more_concurrent_user_count)));
}

void compare_with_follower_count() {
    ChannelInfo channel_have_more_follower(
        ChannelId(Platform::CHZZK, "12345"),
        ChannelDetail("testing", 999, 12, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    ChannelInfo channel_have_less_follower(
        ChannelId(Platform::CHZZK, "99999"),
        ChannelDetail("testing", 123, 12, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    // 전제조건1 : 둘의 is_open이 같아야 함
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(channel_have_more_follower, channel_have_less_follower));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_is_open(channel_have_less_follower, channel_have_more_follower));

    // 전제조건2 : 둘의 priority가 같아야 함
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_priority(channel_have_more_follower, channel_have_less_follower));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_priority(channel_have_less_follower, channel_have_more_follower));

    // 전제조건3 : 둘의 is_open이 false
    TEST_ASSERT_FALSE(channel_have_more_follower.get_live_state()->get_is_open());
    TEST_ASSERT_FALSE(channel_have_less_follower.get_live_state()->get_is_open());

    // 전제조건3 : 둘의 follower로 비교가능
    TEST_ASSERT_TRUE(ChannelInfoCmp::compare_with_follower_count(channel_have_more_follower, channel_have_less_follower));
    TEST_ASSERT_FALSE(ChannelInfoCmp::compare_with_follower_count(channel_have_less_follower, channel_have_more_follower));

    // 둘의 라이브 상태, 우선순위가 같을 때 concurrent user count로 결정됨
    TEST_ASSERT_TRUE(cmp(channel_have_more_follower, channel_have_less_follower));
    TEST_ASSERT_FALSE(cmp(channel_have_less_follower, channel_have_more_follower));

    // shared_ptr에서도 동일하게 작동
    TEST_ASSERT_TRUE(cmp(std::make_shared<ChannelInfo>(channel_have_more_follower), std::make_shared<ChannelInfo>(channel_have_less_follower)));
    TEST_ASSERT_FALSE(cmp(std::make_shared<ChannelInfo>(channel_have_less_follower), std::make_shared<ChannelInfo>(channel_have_more_follower)));
}

void test_channel_info_cmp() {
    RUN_TEST(compare_with_is_open);
    RUN_TEST(compare_with_priority_when_one_channel_has_not_priority);
    RUN_TEST(compare_with_priority_when_both_channels_have_priority);
    RUN_TEST(compare_with_concurrent_user_count);
    RUN_TEST(compare_with_follower_count);

    RUN_TEST(use_priority_queue_with_channel_info);
}