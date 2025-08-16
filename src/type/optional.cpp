//
// Created by yareach on 25. 8. 16..
//

#include "type/optional.h"
#include "type/string.h"
#include <cstdint>

template<>
const uint8_t optional<uint8_t>::DEFAULT = 0;

template<>
const int optional<int>::DEFAULT = 0;

template<>
const String optional<String>::DEFAULT = "";

template<>
const bool optional<bool>::DEFAULT = false;