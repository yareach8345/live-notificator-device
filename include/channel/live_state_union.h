//
// Created by yareach on 25. 8. 17..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_UNION_H
#define LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_UNION_H

#include "live_open.h"
#include "live_close.h"

union LiveStateUnion {
    LiveStateUnion(const LiveClose &live_close): close(live_close) {}
    LiveStateUnion(const LiveOpen &live_open): open(live_open) {}
    ~LiveStateUnion() {}

    LiveOpen open;
    LiveClose close;
};

#endif //LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_UNION_H