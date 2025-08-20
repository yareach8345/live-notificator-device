//
// Created by yareach on 25. 8. 19..
//

#include "mqtt/parser.h"
#include "mqtt/topic.h"
#include "mqtt/message/channel_image_changed_message.h"
#include "mqtt/message/channel_state_changed_message.h"
#include "mqtt/message/refreshed_message.h"
#include "mqtt/message/updated_message.h"
#include "ArduinoJson.h"
#include "json/util.h"
#include "mqtt/message/channel_info_changed_message.h"

MessageBase* parse_message(const MqttMessage& mqtt_message) {
    const MessageType message_type = get_message_type_from_topic(mqtt_message.get_topic());

    if (message_type == MessageType::REFRESHED) {
        return new RefreshedMessage();
    }

    if (message_type == MessageType::UPDATED) {
        return new UpdatedMessage();
    }

    const ChannelId channel_id = get_channel_id_from_topic(mqtt_message.get_topic());

    if (message_type == MessageType::STATE_CHANGED) {
        const String new_state_str = mqtt_message.get_payload();
        const ChannelState new_state = ChannelStateUtils::from_string(new_state_str);
        return new ChannelStateChangedMessage(channel_id, new_state);
    }

    if (message_type == MessageType::INFO_CHANGED) {
        const JsonDocument updates = parse_json_string(mqtt_message.get_payload());
        return new ChannelInfoChangedMessage(channel_id, updates);
    }

    if (message_type == MessageType::IMAGE_CHANGED) {
        return new ChannelImageChangedMessage(channel_id);
    }

    return nullptr;
}
