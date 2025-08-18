//
// Created by yareach on 25. 8. 17..
//

#include "channel/live_state_variant.h"

LiveStateVariant::LiveStateVariant(const LiveOpen &live_open): open(live_open), live_state_type(OPEN) {}

LiveStateVariant::LiveStateVariant(const LiveClose &live_close): close(live_close), live_state_type(CLOSE) {}

LiveStateVariant::LiveStateVariant(const LiveStateVariant &other): live_state_type(other.live_state_type) {
    if (other.is_open()) {
        new (&open) LiveOpen(other.open);
    } else {
        new (&close) LiveClose(other.close);
    }
}

LiveStateVariant::~LiveStateVariant() {
    if (is_open()) {
        open.~LiveOpen();
    } else {
        close.~LiveClose();
    }
}

LiveStateVariant& LiveStateVariant::operator=(const LiveStateVariant& rhs) {
    if (this == &rhs) return *this;

    if (live_state_type == OPEN) open.~LiveOpen();
    else if (live_state_type == CLOSE) close.~LiveClose();

    if (rhs.live_state_type == OPEN) {
        new (&open) LiveOpen(rhs.open);
        live_state_type = OPEN;
    } else if (rhs.live_state_type == CLOSE) {
        new (&close) LiveClose(rhs.close);
        live_state_type = CLOSE;
    }

    return *this;
}

void LiveStateVariant::set_live_state(const LiveClose &live_close) {
    if (live_state_type == OPEN) {
        open.~LiveOpen();
    }
    live_state_type = CLOSE;
    new (&close) LiveClose(live_close);
}

void LiveStateVariant::set_live_state(const LiveOpen &live_open) {
    if (live_state_type == CLOSE) {
        close.~LiveClose();
    }
    live_state_type = OPEN;
    new (&open) LiveOpen(live_open);
}

LiveOpen LiveStateVariant::get_live_state_by_open() const {
    return open;
}

LiveOpen* LiveStateVariant::get_live_state_by_open_ref() {
    return &open;
}

LiveClose LiveStateVariant::get_live_state_by_close() const {
    return close;
}

LiveClose *LiveStateVariant::get_live_state_by_close_ref() {
    return &close;
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
