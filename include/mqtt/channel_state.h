//
// Created by yareach on 25. 8. 18..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_STATE_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_STATE_H

#include "type/string.h"

enum ChannelState {
    OPEN, CLOSE, ADDED, DELETED
};

class ChannelStateUtils {
public:
    static String to_string(ChannelState state);
    static ChannelState from_string(const String& state_str);
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_STATE_H