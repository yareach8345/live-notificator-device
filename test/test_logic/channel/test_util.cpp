//
// Created by yareach on 25. 8. 21..
//

#include <unity.h>
#include "channel/util.h"

void test_get_channel_id_str() {
    const String chzzk_channel_id_str = get_channel_id_str(ChannelId(CHZZK, "12345"));
    const String youtube_channel_id_str = get_channel_id_str(ChannelId(YOUTUBE, "12345"));

    TEST_ASSERT_EQUAL_STRING("chzzk-12345", chzzk_channel_id_str.c_str());
    TEST_ASSERT_EQUAL_STRING("youtube-12345", youtube_channel_id_str.c_str());
}

void test_util() {
    RUN_TEST(test_get_channel_id_str);
}