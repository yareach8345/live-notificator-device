//
// Created by yareach on 25. 8. 18..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_PARSER_H
#define LIVE_NOTIFICATOR_DEVICE_PARSER_H

#include <ArduinoJson.h>
#include "message/refreshed_message.h"
#include "message/updated_message.h"

//todo 1: 타입별 메시지 클래스 정의
//todo 2: 파싱 함수 구현

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

RefreshedMessage parse_refreshed_message(const JsonObjectConst& json);

UpdatedMessage parse_updated_message(const JsonObjectConst& json);

#endif //LIVE_NOTIFICATOR_DEVICE_PARSER_H