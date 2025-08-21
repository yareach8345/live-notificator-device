//
// Created by yareach on 25. 8. 21..
//

#include <unity.h>
#include "channel/channel_info.h"
#include "channel/channel_info_cmp.h"
#include "channel/channel_store.h"
#include "channel/live_close.h"
#include "channel/live_open.h"

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

void test_channel_store_generate() {
    ChannelStore empty_cs;

    ChannelStore not_empty_cs(std::vector<ChannelInfo>{ch1, ch2, ch3, ch4, ch5, ch6});

    TEST_ASSERT_EQUAL(0, empty_cs.get_number_of_channels());
    TEST_ASSERT_EQUAL(6, not_empty_cs.get_number_of_channels());

    TEST_ASSERT_EQUAL(0, empty_cs.get_number_of_open_channels());
    TEST_ASSERT_EQUAL(3, not_empty_cs.get_number_of_open_channels());

    TEST_ASSERT_EQUAL(0, empty_cs.get_number_of_close_channels());
    TEST_ASSERT_EQUAL(3, not_empty_cs.get_number_of_close_channels());

    const auto channels = not_empty_cs.get_sorted_channel_list();
    for (int i = 0; i < 1; i++) {
        const auto expect_id = std::to_string(i + 1);
        TEST_ASSERT_EQUAL_STRING(expect_id.c_str(), channels[i]->get_channel_id().get_id().c_str());
    }
}

void test_channel_store_add_channel() {
    ChannelStore cs(std::vector<ChannelInfo>{ch1, ch2, ch3, ch4, ch5, ch6});

    ChannelInfoCmp cmp;

    const ChannelInfo new_channel(
        ChannelId(Platform::CHZZK, "new"),
        ChannelDetail("testing", 150, 1, String("#ffffff")),
        std::make_shared<LiveClose>()
    );

    cs.add_channel(new_channel);

    const auto channels = cs.get_sorted_channel_list();
    String ids = "/";
    for (const auto &channel : channels) {
        ids += channel->get_channel_id().get_id() + "/";
    }

    TEST_ASSERT_EQUAL(7, cs.get_number_of_channels());
    TEST_ASSERT_EQUAL(3, cs.get_number_of_open_channels());
    TEST_ASSERT_EQUAL(4, cs.get_number_of_close_channels());

    TEST_ASSERT_EQUAL_STRING("/1/2/3/new/4/5/6/", ids.c_str());
    TEST_ASSERT_FALSE(cmp(channels[2], channels[3]));
    TEST_ASSERT_FALSE(cmp(channels[3], channels[4]));
}

void test_channel_store_delete_channel() {
    ChannelStore cs(std::vector<ChannelInfo>{ch1, ch2, ch3, ch4, ch5, ch6});

    cs.delete_channel(ChannelId(CHZZK, "5"));

    TEST_ASSERT_EQUAL(5, cs.get_number_of_channels());
    TEST_ASSERT_EQUAL(3, cs.get_number_of_open_channels());
    TEST_ASSERT_EQUAL(2, cs.get_number_of_close_channels());

    const auto channels = cs.get_sorted_channel_list();
    String ids = "/";
    for (const auto &channel : channels) {
        ids += channel->get_channel_id().get_id() + "/";
    }

    TEST_ASSERT_EQUAL_STRING("/1/2/3/4/6/", ids.c_str());
}

void test_channel_store_get_channel_by_id() {
    ChannelStore cs(std::vector<ChannelInfo>{ch1, ch2, ch3, ch4, ch5, ch6});

    const std::shared_ptr<ChannelInfo> result = cs.get_channel(ChannelId(CHZZK, "3"));

    TEST_ASSERT_EQUAL(CHZZK, result->get_channel_id().get_platform());
    TEST_ASSERT_EQUAL_STRING("3", result->get_channel_id().get_id().c_str());
}

void test_channel_update() {

}

void test_channel_store() {
    RUN_TEST(test_channel_store_generate);
    RUN_TEST(test_channel_store_add_channel);
    RUN_TEST(test_channel_store_delete_channel);
    RUN_TEST(test_channel_store_get_channel_by_id);
    // RUN_TEST(test_channel_update);
}