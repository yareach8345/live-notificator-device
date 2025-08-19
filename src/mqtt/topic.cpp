//
// Created by yareach on 25. 8. 19..
//

#include "mqtt/topic.h"

#include "channel/channel_id.h"
#include "error/bad_topic_error.h"
#include "string/util.h"


// 예시 메시지

// topic:
// chzzk-notification/refreshed-at

// topic:
// chzzk-notification/updated-at

// topic:
// chzzk-notification/channel/chzzk/afff6e3cc8c1487bc4135bc896811dcc/info-changed
//
// messages:
// {\"concurrentUserCount\":106}
// {\"followerCount\":49758}

// topic:
// chzzk-notification/channel/chzzk/afff6e3cc8c1487bc4135bc896811dcc/state
//
// messages:
// open
// closed

MessageType get_message_type_from_topic(const String& topic) {
    const std::vector<String> split_topic = split(topic, '/');

    if (split_topic.size() < 2) {
        throw BadTopicError("토픽 '" + topic + "'은 유효하지 않습니다. 토픽의 depth는 2이상 이어야 힙니다.");
    }

    if (split_topic[0] != "chzzk-notification") {
        throw BadTopicError("토픽 '" + topic + "'은 유효하지 않습니다. 본 서비스의 토픽은 'chzzk-notification'으로 시작해야 합니다.");
    }

    // 서버 이벤트
    if (split_topic[1] == "refreshed-at") {
        return REFRESHED;
    }
    if (split_topic[1] == "updated-at") {
        return UPDATED;
    }

    // 채널 이벤트
    // 채널 이벤트 조건 확인
    if (split_topic[1] != "channel") {
        throw BadTopicError("토픽 '" + topic + "'은 유효하지 않습니다. 두번째로 'channel'이 와야 합니다.");
    }

    if (split_topic[4] == "info-changed") {
        return INFO_CHANGED;
    }
    if (split_topic[4] == "state") {
        return STATE_CHANGED;
    }
    if (split_topic[4] == "image") {
        return IMAGE_CHANGED;
    }

    throw BadTopicError("토픽 '" + topic + "'은 유효하지 않습니다. '" + split_topic[1] + "'은 지원 되는 이벤트 타입이 아닙니다.");
}

ChannelId get_channel_id_from_topic(const String& topic) {
    const MessageType message_type = get_message_type_from_topic(topic);

    if (message_type != INFO_CHANGED && message_type != STATE_CHANGED && message_type != IMAGE_CHANGED) {
        throw BadTopicError("토픽 '" + topic + "'은 유효하지 않습니다. 채널에 관련된 메시지의 토픽만 channel id를 가져올 수 있습니다.");
    }

    const std::vector<String> split_topic = split(topic, '/');

    const String& platform = split_topic[2];
    const String& id = split_topic[3];

    return { PlatformUtils::from_string(platform), id };
}