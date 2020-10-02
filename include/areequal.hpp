#pragma once

#include <string>
#include <vector>

namespace std {
template <typename T>
inline std::string to_string(const std::vector<T>& t) {
    std::string res;
    res += "[";

    int max = t.size() - 1;
    for (int i = 0; i <= max; ++i) {
        res += to_string(t[i]);
        if (i != max) {
            res += ",";
        }
    }

    res += "]";
    return res;
}
}  // namespace std

namespace leetcode {
template <typename T>
inline bool areEqual(const T& a, const T& b) {
    return std::to_string(a) == std::to_string(b);
}

inline bool areEqual(const std::string& a, const std::string& b) {
    return a == b;
}
}  // namespace leetcode