//
// Created by yareach on 25. 8. 13..
//

#include "channel/live_open.h"

#include <cstdio>

bool LiveOpen::get_is_open() const {
    return true;
}

void LiveOpen::set_live_title(const String &new_live_title) {
    this->live_title = new_live_title;
}

const String* const LiveOpen::get_live_title() const {
    return &live_title;
}

void LiveOpen::set_category(const String &new_category) {
    this->category = new_category;
}

const String* const LiveOpen::get_category() const {
    return &category;
}

void LiveOpen::set_concurrent_user_count(const int &new_concurrent_user_count) {
    this->concurrent_user_count = new_concurrent_user_count;
}

const int* const LiveOpen::get_concurrent_user_count() const {
    return &concurrent_user_count;
}
