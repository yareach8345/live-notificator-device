//
// Created by yareach on 25. 8. 15..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_ID_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_ID_H

#include "type/string.h"

class ChannelId {
private:
    const String* platform;
    const String id;
public:
    ChannelId(const String* _platform, const String& id) : platform(_platform), id(id) {}
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_ID_H