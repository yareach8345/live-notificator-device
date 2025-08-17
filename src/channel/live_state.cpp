//
// Created by yareach on 25. 8. 17..
//

#include "channel/live_state.h"

LiveStateType LiveState::get_live_state_type() const {
    return get_is_open() ? LiveStateType::OPEN : LiveStateType::CLOSE;
}