//
// Created by yareach on 25. 8. 14..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_UTIL_H
#define LIVE_NOTIFICATOR_DEVICE_UTIL_H
#include "live_state.h"
#include "live_open.h"
#include "live_close.h"
#include <ArduinoJson.h>
#include "channel_detail.h"
#include "channel_id.h"

LiveOpen* parse_live_open(const JsonObjectConst &live_open_json);

LiveClose* parse_live_close(const JsonObjectConst &live_close_json);

LiveState* parse_live_state_from_json(const JsonObjectConst &live_state_json_doc);

ChannelId parse_channel_id(const JsonObjectConst &channel_id_json_doc);

ChannelDetail parse_channel_detail(const JsonObjectConst &channel_detail_json_doc);

#endif //LIVE_NOTIFICATOR_DEVICE_UTIL_H
