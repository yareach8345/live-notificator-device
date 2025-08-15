//
// Created by yareach on 25. 8. 15..
//

#include "channel/channel_id.h"

Platform ChannelId::get_platform() const {
    return platform;
}


String ChannelId::get_id() const {
    return id;
}
