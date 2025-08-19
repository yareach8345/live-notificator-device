//
// Created by yareach on 25. 8. 18..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_UPDATED_MESSAGE_H
#define LIVE_NOTIFICATOR_DEVICE_UPDATED_MESSAGE_H

#include "../message_type.h"
#include "message_base.h"

class UpdatedMessage final : public MessageBase {
public:
    MessageType get_message_type() const override;
};

#endif //LIVE_NOTIFICATOR_DEVICE_UPDATED_MESSAGE_H