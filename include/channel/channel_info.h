//
// Created by yareach on 25. 8. 17..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_H

#include <memory>

#include "channel_id.h"
#include "channel_detail.h"
#include "live_state.h"

class ChannelInfo {
private:
    const ChannelId channel_id;
    ChannelDetail detail;
    std::shared_ptr<LiveState> live_state;
public:
    ChannelInfo(const ChannelId& channel_id, const ChannelDetail& detail, const std::shared_ptr<LiveState> &live_state);

    ChannelId get_channel_id() const;

    ChannelDetail get_detail() const;

    ChannelDetail *get_detail_ref();
    void set_detail(const ChannelDetail& new_detail);

    std::shared_ptr<LiveState> get_live_state();
    void set_live_state(const std::shared_ptr<LiveState> &new_live_state);

    LiveStateType get_live_state_type() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_H