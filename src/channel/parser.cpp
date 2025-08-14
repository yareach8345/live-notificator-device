//
// Created by yareach on 25. 8. 14..
//
#include "channel/live_close.h"
#include "channel/live_open.h"
#include "error/json_parsing_fail_error.h"
#include "json/util.h"

const LiveOpen* parse_live_open(const JsonObjectConst &live_open_json) {
    const auto get_required_field = make_get_required_field("LiveOpen", live_open_json);

    if (live_open_json["isOpen"].isNull()) {
        throw JsonParsingFailError("파싱 에러 [LiveOpen]: 필드 isOpen을 찾을 수 없음.");
    }

    const JsonVariantConst is_open = get_required_field("isOpen");

    if (is_open.as<bool>() == false) {
        throw JsonParsingFailError("파싱 에러 [LiveOpen]: 필드 isOpen이 false입니다.");
    }

    const String live_title = get_required_field("liveTitle");
    const String category = get_required_field("category");
    const int concurrent_user_count = get_required_field("concurrentUserCount");

    return new LiveOpen(live_title, category, concurrent_user_count);
}

const LiveClose* parse_live_close(const JsonObjectConst &live_close_json) {
    const auto get_required_field = make_get_required_field("LiveClose", live_close_json);

    const JsonVariantConst is_open = get_required_field("isOpen");

    if (is_open.as<bool>() == true) {
        throw JsonParsingFailError("파싱 에러 [LiveClose]: 필드 isOpen이 true입니다.");
    }

    return new LiveClose();
}

const LiveState* parse_live_state_from_json(const JsonObjectConst &live_state_json_doc) {
    if (live_state_json_doc.isNull()) {
        throw JsonParsingFailError("LiveState 파싱 에러.  json이 null");
    }

    const JsonVariantConst isOpen = live_state_json_doc["isOpen"];
    if (isOpen.isNull()) {
        throw JsonParsingFailError("LiveState 파싱 에러. isOpen을 찾을 수 없음.");
    }

    if (!isOpen.as<bool>()) {
        return parse_live_close(live_state_json_doc);
    }

    return parse_live_open(live_state_json_doc);
}
