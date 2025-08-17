//
// Created by yareach on 25. 8. 17..
//

#include "channel/channel_detail.h"

String ChannelDetail::get_display_name() const { return display_name; }

void ChannelDetail::set_display_name(const String& new_display_name) { this->display_name = new_display_name; }

long ChannelDetail::get_follower_count() const { return follower_count; }

void ChannelDetail::set_follower_count(const long& new_follower_count) { this->follower_count = new_follower_count; }

optional<uint8_t> ChannelDetail::get_priority() const { return priority; }

bool ChannelDetail::is_priority_empty() const { return priority.is_empty(); }

void ChannelDetail::set_priority(const uint8_t new_priority) { this->priority.set_value(new_priority); }

void ChannelDetail::set_priority_to_null() { this->priority.set_value_to_null(); }

optional<String> ChannelDetail::get_color() const { return color; }

bool ChannelDetail::is_color_empty() const { return color.is_empty(); }

void ChannelDetail::set_color(const String& new_color) { this->color.set_value(new_color); }

void ChannelDetail::set_color_to_null() {
    this->color.set_value_to_null();
}