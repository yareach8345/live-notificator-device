//
// Created by yareach on 25. 8. 19..
//

#include "string/util.h"

std::vector<String> split(String str, char delimiter) {
    std::vector<String> tokens;
    String temp = "";

    if (str.length() == 0) {
        return std::move(tokens);
    }

    for (size_t index = 0; index <= str.length(); index++) {
        if (str[index] == delimiter || index == str.length()) {
            tokens.push_back(std::move(temp));
            temp = "";
        } else {
            temp += str[index];
        }
    }

    return std::move(tokens);
}