//
// Created by yareach on 25. 8. 15..
//

#include "channel/channel_id.h"

const Platform* const ChannelId::get_platform() const {
    return &platform;
}


const String* const ChannelId::get_id() const {
    return &id;
}
