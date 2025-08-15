//
// Created by yareach on 25. 8. 15..
//

#include <unity.h>
#include "type/string.h"
#include "channel/platform.h"

void test_transform_from_string() {
    const String chzzk_platform_string = "chzzk";
    const String youtube_platform_string = "youtube";

    const Platform chzzk_platform = PlatformUtils::from_string(chzzk_platform_string);
    const Platform youtube_platform = PlatformUtils::from_string(youtube_platform_string);

    TEST_ASSERT_EQUAL(Platform::CHZZK, chzzk_platform);
    TEST_ASSERT_EQUAL(Platform::YOUTUBE, youtube_platform);
}

void test_transform_to_string() {
    const String chzzk_transform_result = PlatformUtils::to_string(Platform::CHZZK);
    const String youtube_transform_result = PlatformUtils::to_string(Platform::YOUTUBE);

    TEST_ASSERT_EQUAL_STRING("chzzk", chzzk_transform_result.c_str());
    TEST_ASSERT_EQUAL_STRING("youtube", youtube_transform_result.c_str());
}

void test_platform() {
    RUN_TEST(test_transform_from_string);
    RUN_TEST(test_transform_to_string);
}