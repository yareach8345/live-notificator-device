//
// Created by yareach on 25. 8. 15..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_ID_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_ID_H

#include <utility>
#include "platform.h"
#include "type/string.h"

class ChannelId {
private:
    const Platform platform;
    const String id;
public:
    ChannelId(const Platform _platform, String id) : platform(_platform), id(std::move(id)) {}

    Platform get_platform() const;

    String get_id() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_ID_H