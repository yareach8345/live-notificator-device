//
// Created by yareach on 25. 8. 15..
//

#include <unity.h>
#include <stdexcept>
#include "type/string.h"
#include "channel/platform.h"

namespace std {
    class runtime_error;
}

void test_transform_from_string() {
    const String chzzk_platform_string = "chzzk";
    const String youtube_platform_string = "youtube";

    const Platform chzzk_platform = PlatformUtils::from_string(chzzk_platform_string);
    const Platform youtube_platform = PlatformUtils::from_string(youtube_platform_string);

    TEST_ASSERT_EQUAL(Platform::CHZZK, chzzk_platform);
    TEST_ASSERT_EQUAL(Platform::YOUTUBE, youtube_platform);
}

void test_transform_from_unknown_platform() {
    try {
        const String unknown_platform_string = "unknown";
        const Platform unknown_platform = PlatformUtils::from_string(unknown_platform_string);

        TEST_FAIL_MESSAGE("Unexpected success");
    } catch (const std::runtime_error& error) {
        TEST_ASSERT_EQUAL_STRING("[String to Platform 과정의 에러] unknown 플랫폼은 지원되지 않습니다.", error.what());
    }
}

void test_transform_to_string() {
    const String chzzk_transform_result = PlatformUtils::to_string(Platform::CHZZK);
    const String youtube_transform_result = PlatformUtils::to_string(Platform::YOUTUBE);

    TEST_ASSERT_EQUAL_STRING("chzzk", chzzk_transform_result.c_str());
    TEST_ASSERT_EQUAL_STRING("youtube", youtube_transform_result.c_str());
}

void test_platform() {
    RUN_TEST(test_transform_from_string);
    RUN_TEST(test_transform_from_unknown_platform);
    RUN_TEST(test_transform_to_string);
}