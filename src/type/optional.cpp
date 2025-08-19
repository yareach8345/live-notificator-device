//
// Created by yareach on 25. 8. 16..
//

#include "type/optional.h"
#include "type/string.h"
#include <cstdint>

template<>
unsigned char optional<unsigned char>::get_default() { return 0; }

template<>
long optional<long>::get_default() { return 0; }

template<>
int optional<int>::get_default() { return 0; }

template<>
String optional<String>::get_default() { return ""; }

template<>
bool optional<bool>::get_default() { return false; }
