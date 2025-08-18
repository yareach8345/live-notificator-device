//
// Created by yareach on 25. 8. 17..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_VARIANT_H
#define LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_VARIANT_H

#include "live_open.h"
#include "live_close.h"

class LiveStateVariant {
private:
    // LiveStateUnion live_state;
    union {
        LiveOpen open;
        LiveClose close;
    };
    LiveStateType live_state_type;
public:
    LiveStateVariant(const LiveOpen &live_open);
    LiveStateVariant(const LiveClose &live_close);
    LiveStateVariant(const LiveStateVariant& other);
    ~LiveStateVariant();

    LiveStateVariant& operator=(const LiveStateVariant& rhs);

    void set_live_state(const LiveOpen& live_open);

    void set_live_state(const LiveClose& live_close);

    LiveOpen get_live_state_by_open() const;

    LiveOpen* get_live_state_by_open_ref();

    LiveClose get_live_state_by_close() const;

    LiveClose* get_live_state_by_close_ref();

    LiveStateType get_live_state_type() const;

    bool is_open() const;

    bool is_closed() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_LIVE_STATE_VARIANT_H