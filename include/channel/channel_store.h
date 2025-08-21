//
// Created by yareach on 25. 8. 21..
//

#ifndef LIVE_NOTIFICATOR_DEVICE_CHANNEL_STORE_H
#define LIVE_NOTIFICATOR_DEVICE_CHANNEL_STORE_H

#include "ArduinoJson.h"
#include <map>
#include <vector>
#include "type/string.h"
#include "channel_info.h"

class ChannelStore {
private:
    std::map<String, ChannelInfo> channel_map;
    std::vector<std::shared_ptr<ChannelInfo>> sorted_channel_list;
    bool is_need_update_list;
    size_t open_channel_count;

    void update_store();
    void update_open_channel_count();
    void update_channel_list();
public:
    explicit ChannelStore();
    explicit ChannelStore(std::vector<ChannelInfo> channels);
    void add_channel(const ChannelInfo &channel_info);
    void delete_channel(const ChannelId &channel_id);
    void update_channel_info(const ChannelId &channel_id, const JsonObjectConst &updates);
    void update_channel_state(const ChannelId &channel_id, const LiveStateType &new_state);
    size_t get_number_of_channels() const;
    size_t get_number_of_open_channels();
    size_t get_number_of_close_channels();
    std::shared_ptr<ChannelInfo> get_channel(const ChannelId &channel_id);
    std::vector<std::shared_ptr<ChannelInfo>> get_sorted_channel_list();
};

#endif //LIVE_NOTIFICATOR_DEVICE_CHANNEL_STORE_H