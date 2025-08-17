//
// Created by yareach on 25. 8. 17..
//

#include "channel/live_state_variant.h"

LiveStateVariant::LiveStateVariant(const LiveOpen &live_open): open(live_open), live_state_type(OPEN) {}

LiveStateVariant::LiveStateVariant(const LiveClose &live_close): close(live_close), live_state_type(CLOSE) {}

LiveStateVariant::LiveStateVariant(const LiveStateVariant &other): live_state_type(other.live_state_type) {
    if (other.is_open()) {
        open = other.get_live_state_by_open();
    } else {
        close = other.get_live_state_by_close();
    }
}

LiveStateVariant::~LiveStateVariant() {
    if (is_open()) {
        open.~LiveOpen();
    } else {
        close.~LiveClose();
    }
}


void LiveStateVariant::set_live_state(const LiveClose &live_close) {
    live_state_type = CLOSE;
    if (live_state_type == OPEN) {
        open.~LiveOpen();
    }
    new (&close) LiveClose(live_close);
}

void LiveStateVariant::set_live_state(const LiveOpen &live_open) {
    live_state_type = OPEN;
    if (live_state_type == CLOSE) {
        close.~LiveClose();
    }
    new (&open) LiveOpen(live_open);
}

LiveOpen LiveStateVariant::get_live_state_by_open() const {
    return open;
}

LiveClose LiveStateVariant::get_live_state_by_close() const {
    return close;
}

LiveStateType LiveStateVariant::get_live_state_type() const {
    return live_state_type;
}

bool LiveStateVariant::is_open() const {
    return live_state_type == OPEN;
}

bool LiveStateVariant::is_closed() const {
    return live_state_type == CLOSE;
}
