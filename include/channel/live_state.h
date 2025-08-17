//
// Created by yareach on 25. 8. 13..
//
#ifndef LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_H
#define LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_H
#include "live_state_types.h"

class LiveState {
public:
    virtual ~LiveState() = default;
    virtual bool get_is_open() const = 0;
    LiveStateType get_live_state_type() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_H