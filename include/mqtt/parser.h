//
// Created by yareach on 25. 8. 19..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_PARSER_H
#define LIVE_NOTIFICATOR_DEVICE_PARSER_H

#include "mqtt_message.h"
#include "message/message_base.h"

MessageBase* parse_message(const MqttMessage& mqtt_message);

#endif //LIVE_NOTIFICATOR_DEVICE_PARSER_H
