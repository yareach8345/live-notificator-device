//
// Created by yareach on 25. 8. 16..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_OPTIONAL_H
#define LIVE_NOTIFICATOR_DEVICE_OPTIONAL_H

#include "error/can_not_read_from_optional_error.h"

template <typename T>
class optional {
private:
    T _value;
    bool _is_empty;
public:
    optional(const T& value): _value(value), _is_empty(false) {}

    optional(): _value(get_default()), _is_empty(true) {}

    static T get_default();

    static optional<T> create(const T& value) {
        return optional<T>(value);
    }

    static optional<T> get_null() {
        return optional<T>();
    }

    void set_value(const T& value) {
        this->_value = value;
        this->_is_empty = false;
    }

    void set_value_to_null() {
        this->_is_empty = true;
    }

    T get_value() const {
        if (this->_is_empty) {
            throw CanNotReadFromOptionalError();
        }

        return this->_value;
    }

    T get_value_or_default() const {
        return this->_is_empty ? get_default(): this->_value;
    }

    T get_value_or(const T& default_value) const {
        return this->_is_empty ? default_value: this->_value;
    }

    T get_value_unsafe() const {
        return this->_value;
    }

    bool is_empty() const {
        return this->_is_empty;
    }
};

#endif //LIVE_NOTIFICATOR_DEVICE_OPTIONAL_H