//
// Created by yareach on 25. 8. 13..
//
#ifndef LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_H
#define LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_H

class LiveState {
public:
    virtual ~LiveState() = default;
    virtual bool get_is_open() const = 0;
};

#endif //LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_H