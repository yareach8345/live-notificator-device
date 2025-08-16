//
// Created by yareach on 25. 8. 16..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CAN_NOT_READ_FROM_OPTIONAL_ERROR_H
#define LIVE_NOTIFICATOR_DEVICE_CAN_NOT_READ_FROM_OPTIONAL_ERROR_H
#include <stdexcept>

class CanNotReadFromOptionalError final : public std::runtime_error {
public:
    CanNotReadFromOptionalError(): runtime_error("optional로 부터 값을 읽어올 수 없습니다. optional이 null값을 가지고 있습니다.") {}
};

#endif //LIVE_NOTIFICATOR_DEVICE_CAN_NOT_READ_FROM_OPTIONAL_ERROR_H