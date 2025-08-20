//
// Created by yareach on 25. 8. 15..
//

#include "channel/platform.h"
#include <stdexcept>

#include "error/parsing_fail_error.h"

String PlatformUtils::to_string(const Platform platform) {
    switch (platform) {
        case CHZZK:
            return "chzzk";
        case YOUTUBE:
            return "youtube";
        default:
            throw std::runtime_error("[Platform to String 과정의 에러] 알 수 없는 Platform입니다.");
    }
}

Platform PlatformUtils::from_string(const String& platform) {
    if (platform == "chzzk") {
        return CHZZK;
    }
    if (platform == "youtube") {
        return YOUTUBE;
    }

    throw ParsingFailError("Platform 파싱 실패. 문자열 '" + platform + "'는 Platform으로 파싱될 수 없습니다.");
}
