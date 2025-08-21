//
// Created by yareach on 25. 8. 21..
//

#include <queue>
#include "channel/channel_store.h"
#include "channel/channel_info_cmp.h"
#include "channel/util.h"

ChannelStore::ChannelStore(): is_need_update_list(false), open_channel_count(0) {}

ChannelStore::ChannelStore(std::vector<ChannelInfo> channels): is_need_update_list(false) {
    for (ChannelInfo &channel : channels) {
        const String channel_id_str = get_channel_id_str(channel.get_channel_id());
        this->channel_map.insert({channel_id_str, channel});
    }
    update_store();
}

void ChannelStore::update_store() {
    update_channel_list();
    update_open_channel_count();
}

void ChannelStore::update_open_channel_count() {
    open_channel_count = 0;

    for (auto &channel : this->channel_map) {
        if (channel.second.get_live_state()->get_is_open()) {
            open_channel_count++;
        }
    }
}

void ChannelStore::update_channel_list() {
    std::priority_queue<std::shared_ptr<ChannelInfo>, std::vector<std::shared_ptr<ChannelInfo>>, ChannelInfoCmp> pq;
    this->sorted_channel_list.clear();

    for (auto &channel : this->channel_map) {
        const auto channel_sp = std::make_shared<ChannelInfo>(channel.second);
        pq.push(channel_sp);
    }

    while (!pq.empty()) {
        this->sorted_channel_list.push_back(pq.top());
        pq.pop();
    }
    this->is_need_update_list = false;
}

void ChannelStore::add_channel(const ChannelInfo &channel_info) {
    const String channel_id_str = get_channel_id_str(channel_info.get_channel_id());
    this->channel_map.insert({channel_id_str, channel_info});
    this->is_need_update_list = true;
}

void ChannelStore::delete_channel(const ChannelId &channel_id) {
    this->channel_map.erase(get_channel_id_str(channel_id));
    this->is_need_update_list = true;
}

std::shared_ptr<ChannelInfo> ChannelStore::get_channel(const ChannelId &channel_id) {
    return std::make_shared<ChannelInfo>(this->channel_map.at(get_channel_id_str(channel_id)));
}

std::vector<std::shared_ptr<ChannelInfo>> ChannelStore::get_sorted_channel_list() {
    if (this->is_need_update_list) {
        this->update_store();
    }

    std::vector<std::shared_ptr<ChannelInfo>> result;
    for (const auto &channel: this->sorted_channel_list) {
        result.push_back(channel);
    }
    return result;
}

void ChannelStore::update_channel_info(const ChannelId &channel_id, const JsonObjectConst &updates) {
    //todo : 업데이트 로직 작성하기
    this->is_need_update_list = true;
}

void ChannelStore::update_channel_state(const ChannelId &channel_id, const LiveStateType &new_state) {
    //todo : 업데이트 로직 작성하기
    this->is_need_update_list = true;
}

size_t ChannelStore::get_number_of_channels() const {
    return this->channel_map.size();
}

size_t ChannelStore::get_number_of_open_channels() {
    if (is_need_update_list) {
        update_store();
    }

    return open_channel_count;
}

size_t ChannelStore::get_number_of_close_channels() {
    if (is_need_update_list) {
        update_store();
    }

    return get_number_of_channels() - open_channel_count;
}

