#pragma once

#include <stack>
#include <string>
#include <vector>

#include "stringconvert.hpp"
#include "testexception.hpp"

namespace leetcode {
template <class _T>
inline _T toValue(const std::string& s) {
    throw TestException("Can not get value of \"" + s + "\"!");
}

template <>
inline int toValue(const std::string& s) {
    return std::stoi(s);
}

template <>
inline int64_t toValue(const std::string& s) {
    return std::stoll(s);
}

template <>
inline double toValue(const std::string& s) {
    return std::stod(s);
}

template <>
inline char toValue(const std::string& s) {
    return s.front();
}

template <>
inline std::string toValue(const std::string& s) {
    return s;
}

template<class _T>
static inline _T temp2value(std::string& temp) {
    trim(temp, ' ');
    if (temp.front() == '\'' || temp.front() == '\"') {
        temp.erase(temp.begin());
    }

    if (temp.back() == '\'' || temp.back() == '\"') {
        temp.pop_back();
    }

    _T value = toValue<_T>(temp);
    temp.clear();
    return value;
} 

template <class _T>
inline std::vector<_T> toArray(const std::string& s) {
    std::string src = s;
    trim(src, ' ');
    if (src.front() != '[' || src.back() != ']') {
        throw TestException("\"" + s + "\" is not an array!");
    }

    src.erase(src.begin());
    src.pop_back();
    std::vector<_T> res;
    std::string temp;
    std::stack<char> st;  //符号栈 [、"、'
    for (char i : src) {
        if (st.empty() && i == ',') {
            res.emplace_back(temp2value<_T>(temp));
            continue;
        }

        temp.push_back(i);
        switch (i) {
            case '[':
                st.push('[');
                break;

            case ']':
                if (st.empty() || st.top() != '[') {
                    throw TestException("\"" + s +
                                        "\" is an error array string!");
                }

                st.pop();
                break;

            case '\'':
            case '\"':
                if (st.empty() || st.top() != i) {
                    st.push(i);
                } else {
                    st.pop();
                }

                break;

            default:
                break;
        }
    }

    if (!st.empty()) {
        throw TestException("\"" + s + "\" is an error array string!");
    }

    if (!temp.empty()) {
        res.emplace_back(temp2value<_T>(temp));
    }

    return res;
}

template <class _T>
inline std::vector<std::vector<_T>> to2DArray(const std::string& s) {
    std::vector<std::string> subs = toArray<std::string>(s);
    std::vector<std::vector<_T>> res;
    for (auto& sub : subs) {
        res.emplace_back(toArray<_T>(sub));
    }

    return res;
}

template <class _T>
inline std::vector<std::vector<std::vector<_T>>> to3DArray(
    const std::string& s) {
    std::vector<std::string> subs = toArray<std::string>(s);
    std::vector<std::vector<std::vector<_T>>> res;
    for (auto& sub : subs) {
        res.emplace_back(to2DArray<_T>(sub));
    }

    return res;
}
}  // namespace leetcode