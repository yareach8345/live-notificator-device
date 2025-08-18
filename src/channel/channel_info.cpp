//
// Created by yareach on 25. 8. 17..
//

#include "channel/channel_info.h"

ChannelInfo::ChannelInfo(const ChannelId &channel_id, const ChannelDetail &detail, const std::shared_ptr<LiveState> &live_state): channel_id(channel_id), detail(detail), live_state(live_state) {}

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

std::shared_ptr<LiveState> ChannelInfo::get_live_state() {
    return live_state;
}

void ChannelInfo::set_live_state(const std::shared_ptr<LiveState> &new_live_state) {
    this->live_state = new_live_state;
}


LiveStateType ChannelInfo::get_live_state_type() const {
    return this->live_state->get_live_state_type();
}
