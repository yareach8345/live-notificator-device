//
// Created by yareach on 25. 8. 20..
//

#include "mqtt/channel_state.h"

#include "error/parsing_fail_error.h"

ChannelState ChannelStateUtils::from_string(const String &state_str) {
    if (state_str == "open") {
        return OPEN;
    }

    if (state_str == "closed") {
        return CLOSE;
    }

    if (state_str == "added") {
        return ADDED;
    }

    if (state_str == "deleted") {
        return DELETED;
    }

    throw ParsingFailError("ChannelState 파싱 실패. 문자열 '" + state_str + "'는 ChannelState로 파싱될 수 없습니다.");
}

String ChannelStateUtils::to_string(ChannelState state) {
    switch (state) {
        case OPEN:
            return "open";
        case CLOSE:
            return "closed";
        case ADDED:
            return "added";
        case DELETED:
            return "deleted";
        default:
            throw std::runtime_error("[ChannelState to String 과정의 에러] 알 수 없는 ChannelState입니다.");
    }
}