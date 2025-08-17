//
// Created by yareach on 25. 8. 15..
//

// \"detail\":{\"displayName\":\"스트리머1\",\"followerCount\":959,\"priority\":null,\"color\":\"#e7ebee\"}

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_DETAIL_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_DETAIL_H

#include <cstdint>
#include "type/string.h"
#include "type/optional.h"

class ChannelDetail {
private:
    String display_name;
    long follower_count;
    optional<uint8_t> priority;
    optional<String> color;
public:
    ChannelDetail(const String& display_name, long follower_count, const optional<uint8_t> &priority, const optional<String> &color): display_name(display_name), follower_count(follower_count), priority(priority), color(color) {}

    String get_display_name() const;
    void set_display_name(const String& new_display_name);

    long get_follower_count() const;
    void set_follower_count(const long& new_follower_count);

    optional<uint8_t> get_priority() const;
    bool is_priority_empty() const;
    void set_priority(const uint8_t new_priority);
    void set_priority_to_null();

    optional<String> get_color() const;
    bool is_color_empty() const;
    void set_color(const String& new_color);
    void set_color_to_null();
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_DETAIL_H