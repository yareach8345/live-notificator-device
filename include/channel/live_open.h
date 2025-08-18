//
// Created by yareach on 25. 8. 13..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_LIVE_OPEN_H
#define LIVE_NOTIFICATOR_DEVICE_LIVE_OPEN_H
#include <utility>

#include "live_state.h"
#include "type/string.h"

class LiveOpen: public LiveState {
private:
    String live_title;
    String category;
    int concurrent_user_count;
public:
    LiveOpen(String live_title, String category, const int &concurrent_user_count): live_title(std::move(live_title)), category(std::move(category)), concurrent_user_count(concurrent_user_count) {};

    bool get_is_open() const override;

    void set_live_title(const String &new_live_title);
    String get_live_title() const;

    void set_category(const String &new_live_title);
    String get_category() const;

    void set_concurrent_user_count(const int &new_concurrent_user_count);
    long get_concurrent_user_count() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_LIVE_OPEN_H