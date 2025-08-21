//
// Created by yareach on 25. 8. 21..
//

#include "channel/util.h"

#include "channel/platform.h"

const String get_channel_id_str(const ChannelId& channel_id) {
    const String platform_string = PlatformUtils::to_string(channel_id.get_platform());

    return platform_string + "-" + channel_id.get_id();
}
