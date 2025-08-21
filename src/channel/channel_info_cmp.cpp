//
// Created by yareach on 25. 8. 20..
//

#include "channel/channel_info_cmp.h"

bool ChannelInfoCmp::compare_with_is_open(ChannelInfo c1, ChannelInfo c2) {
    return c1.get_live_state()->get_is_open() > c2.get_live_state()->get_is_open();
}

bool ChannelInfoCmp::compare_with_priority(const ChannelInfo &c1, const ChannelInfo &c2) {
    return c1.get_detail().get_priority().get_value_or(255) < c2.get_detail().get_priority().get_value_or(255);
}

bool ChannelInfoCmp::compare_with_concurrent_user_count(ChannelInfo &c1, ChannelInfo &c2) {
    return dynamic_cast<LiveOpen*>(c1.get_live_state().get())->get_concurrent_user_count() > dynamic_cast<LiveOpen*>(c2.get_live_state().get())->get_concurrent_user_count();
}

bool ChannelInfoCmp::compare_with_follower_count(const ChannelInfo &c1, const ChannelInfo &c2) {
    return c1.get_detail().get_follower_count() > c2.get_detail().get_follower_count();
}

bool ChannelInfoCmp::operator()(ChannelInfo c1, ChannelInfo c2) const {
    if (c1.get_live_state()->get_is_open() != c2.get_live_state()->get_is_open()) {
        return compare_with_is_open(c1, c2);
    }

    if (c1.get_detail().get_priority().get_value_or(255) != c2.get_detail().get_priority().get_value_or(255)) {
        return compare_with_priority(c1, c2);
    }

    if (c1.get_live_state()->get_is_open() && c2.get_live_state()->get_is_open()) {
        return compare_with_concurrent_user_count(c1, c2);
    }

    return compare_with_follower_count(c1, c2);
}

bool ChannelInfoCmp::operator()(const std::shared_ptr<ChannelInfo> &c1, const std::shared_ptr<ChannelInfo> &c2) const {
    return (*this)(*c1, *c2);
}
