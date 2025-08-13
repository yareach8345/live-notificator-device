//
// Created by yareach on 25. 8. 13..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_LIVE_CLOSE_H
#define LIVE_NOTIFICATOR_DEVICE_LIVE_CLOSE_H
#include "test_main.h"

class LiveClose: public LiveState {
public:
    bool get_is_open() const override;
};

#endif //LIVE_NOTIFICATOR_DEVICE_LIVE_CLOSE_H