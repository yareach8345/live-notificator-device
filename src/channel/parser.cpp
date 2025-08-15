//
// Created by yareach on 25. 8. 14..
//
#include "channel/live_close.h"
#include "channel/live_open.h"
#include "channel/parser.h"

#include "channel/platform.h"
#include "error/json_parsing_fail_error.h"
#include "json/json_field_getter.h"
#include "json/util.h"

const LiveOpen* parse_live_open(const JsonObjectConst &live_open_json) {
    const JsonFieldGetter field_getter("LiveOpen", live_open_json);

    if (live_open_json["isOpen"].isNull()) {
        throw JsonParsingFailError("파싱 에러 [LiveOpen]: 필드 isOpen을 찾을 수 없음.");
    }

    const JsonVariantConst is_open = field_getter.get_required_field("isOpen");

    if (is_open.as<bool>() == false) {
        throw JsonParsingFailError("파싱 에러 [LiveOpen]: 필드 isOpen이 false입니다.");
    }

    const String live_title = field_getter.get_required_field("liveTitle");
    const String category = field_getter.get_required_field("category");
    const int concurrent_user_count = field_getter.get_required_field("concurrentUserCount");

    return new LiveOpen(live_title, category, concurrent_user_count);
}

const LiveClose* parse_live_close(const JsonObjectConst &live_close_json) {
    const JsonFieldGetter field_getter("LiveClose", live_close_json);

    const JsonVariantConst is_open = field_getter.get_required_field("isOpen");

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

const ChannelId parse_channel_id(const JsonObjectConst &channel_id_json_doc) {
    const JsonFieldGetter field_getter("ChannelId", channel_id_json_doc);

    const String platform_string = field_getter.get_required_field("platform");
    const String id = field_getter.get_required_field("id");

    try {
        const Platform platform = PlatformUtils::from_string(platform_string);
        return ChannelId(platform, id);
    } catch (std::runtime_error& e) {
        throw JsonParsingFailError(e.what());
    }
}
