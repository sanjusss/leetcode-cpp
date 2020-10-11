/*
 * @Author: sanjusss
 * @Date: 2020-10-02 15:59:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 09:24:00
 * @FilePath: \include\stringconvert.hpp
 */
#pragma once

#include <algorithm>
#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <vector>

#include "listnode.h"
#include "treenode.h"

namespace std {
inline bool stob(const std::string &s) { return s == "true"; }
}  // namespace std

namespace leetcode {

inline std::vector<std::string> split(const std::string &s,
                                      const std::string &seperator) {
    std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(seperator, pos)) != std::string::npos) {
        std::string subString(s.substr(prev_pos, pos - prev_pos));

        output.push_back(subString);

        pos += seperator.length();
        prev_pos = pos;
    }

    output.push_back(s.substr(prev_pos));  // Last word
    return output;
}

inline std::vector<std::string> split(const std::string &s, char seperator) {
    std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(seperator, pos)) != std::string::npos) {
        std::string subString(s.substr(prev_pos, pos - prev_pos));
        output.push_back(subString);

        ++pos;
        prev_pos = pos;
    }

    output.push_back(s.substr(prev_pos));  // Last word
    return output;
}

inline std::string &ltrim(std::string &s, std::function<bool(char)> condition) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(condition)));
    return s;
}

// trim from end
inline std::string &rtrim(std::string &s, std::function<bool(char)> condition) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(condition)).base(),
            s.end());
    return s;
}

// trim from both ends
inline std::string &trim(std::string &s, std::function<bool(char)> condition) {
    rtrim(s, condition);
    ltrim(s, condition);
    return s;
}

// trim from both ends
inline std::string &trim(std::string &s, char c) {
    auto condition = [c](char i) -> bool { return i == c; };
    return trim(s, condition);
}

inline std::string replaceAllString(std::string str, const std::string &from,
                                    const std::string &to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos +=
            to.length();  // Handles case where 'to' is a substring of 'from'
    }

    return str;
}
}  // namespace leetcode