//
// Created by yareach on 25. 8. 13..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_LIVE_OPEN_H
#define LIVE_NOTIFICATOR_DEVICE_LIVE_OPEN_H
#include "live_state.h"

#ifdef ESP32_ENV
#include <WString.h>
#elif NATIVE_ENV
#include <string>
typedef std::string String;
#endif

class LiveOpen: public LiveState {
private:
    String live_title;
    String category;
    long concurrent_user_count;
public:
    LiveOpen(String live_title, String category, long concurrent_user_count): live_title(live_title), category(category), concurrent_user_count(concurrent_user_count) {};

    bool get_is_open() const override;

    void set_live_title(const String &new_live_title);
    const String* const get_live_title() const;

    void set_category(const String &new_live_title);
    const String* const get_category() const;

    void set_concurrent_user_count(const long &new_concurrent_user_count);
    const long* const get_concurrent_user_count() const;
};

#endif //LIVE_NOTIFICATOR_DEVICE_LIVE_OPEN_H