/*
 * @Author: sanjusss
 * @Date: 2021-05-28 08:33:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-28 08:58:15
 * @FilePath: \0\0\60\65.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isNumber(string s) {
        string_view sv = s;
        auto p = sv.find_first_of("eE");
        if (p == string_view::npos) {
            return isInteger(sv) || isDecimal(sv);
        }
        else {
            return (isInteger(sv.substr(0, p)) || isDecimal(sv.substr(0, p))) && isInteger(sv.substr(p + 1));
        }
    }

private:
    bool isInteger(string_view s) {
        if (s.empty()) {
            return false;
        }

        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        
        return isDigit(s, false);
    }

    bool isDigit(string_view s, bool emptyTrue) {
        if (s.empty()) {
            return emptyTrue;
        }

        for (char i : s) {
            if (!isdigit(i)) {
                return false;
            }
        }

        return !s.empty();
    }

    bool isDecimal(string_view s) {
        if (s.empty()) {
            return false;
        }

        if (s[0] == '-' || s[0] == '+') {
            s = s.substr(1);
        }

        if (s.size() < 2) {
            return false;
        }

        auto p = s.find('.');
        if (p == string_view::npos) {
            return false;
        }

        return isDigit(s.substr(0, p), true) && isDigit(s.substr(p + 1), true);
    }
};

TEST(&Solution::isNumber)