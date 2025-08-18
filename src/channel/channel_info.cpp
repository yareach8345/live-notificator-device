//
// Created by yareach on 25. 8. 17..
//

#include "channel/channel_info.h"

ChannelInfo::ChannelInfo(const ChannelId &channel_id, const ChannelDetail &detail, const LiveStateVariant &live_state_variant): channel_id(channel_id), detail(detail), live_state_variant(live_state_variant) {}

ChannelId ChannelInfo::get_channel_id() const {
    return channel_id;
}

ChannelDetail ChannelInfo::get_detail() const {
    return detail;
}

ChannelDetail *ChannelInfo::get_detail_ref() {
    return &detail;
}

void ChannelInfo::set_detail(const ChannelDetail& new_detail) {
    this->detail = new_detail;
}

LiveStateVariant ChannelInfo::get_live_state_variant() const {
    return live_state_variant;
}

LiveStateVariant *ChannelInfo::get_live_state_variant_ref() {
    return &live_state_variant;
}

void ChannelInfo::set_live_state_variant(const LiveStateVariant& new_live_state_variant) {
    this->live_state_variant = new_live_state_variant;
}

void ChannelInfo::set_live_state(const LiveClose& live_close) {
    this->live_state_variant.set_live_state(live_close);
}

void ChannelInfo::set_live_state(const LiveOpen& live_open) {
    this->live_state_variant.set_live_state(live_open);
}

LiveStateType ChannelInfo::get_live_state_type() const {
    return this->live_state_variant.get_live_state_type();
}
