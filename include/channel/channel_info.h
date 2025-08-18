//
// Created by yareach on 25. 8. 17..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_H

#include "channel_id.h"
#include "channel_detail.h"
#include "live_state_variant.h"

class ChannelInfo {
private:
    const ChannelId channel_id;
    ChannelDetail detail;
    LiveStateVariant live_state_variant;
public:
    ChannelInfo(const ChannelId& channel_id, const ChannelDetail& detail, const LiveStateVariant& live_state_variant);

    ChannelId get_channel_id() const;

    ChannelDetail get_detail() const;

    ChannelDetail *get_detail_ref();
    void set_detail(const ChannelDetail& new_detail);

    LiveStateVariant get_live_state_variant() const;
    LiveStateVariant* get_live_state_variant_ref();
    void set_live_state_variant(const LiveStateVariant& new_live_state_variant);
    void set_live_state(const LiveClose& live_close);
    void set_live_state(const LiveOpen& live_open);

    LiveStateType get_live_state_type() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_INFO_H