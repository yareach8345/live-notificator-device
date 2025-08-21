//
// Created by yareach on 25. 8. 20..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_CMP_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_CMP_H

#include "channel_info.h"
#include "live_open.h"

struct ChannelInfoCmp {
    static bool compare_with_is_open(ChannelInfo c1, ChannelInfo c2);

    static bool compare_with_priority(const ChannelInfo &c1, const ChannelInfo &c2);

    static bool compare_with_concurrent_user_count(ChannelInfo &c1, ChannelInfo &c2);

    static bool compare_with_follower_count(const ChannelInfo &c1, const ChannelInfo &c2);

    bool operator()(ChannelInfo c1, ChannelInfo c2) const;

    bool operator()(const std::shared_ptr<ChannelInfo> &c1, const std::shared_ptr<ChannelInfo> &c2) const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_CMP_H