#pragma once
#include "leetcode.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string_view, char> s2c;
        unordered_map<char, string_view> c2s;
        string_view sv = s;
        int i = 0;
        string_view::size_type j = 0;
        while (j != string_view::npos) {
            if (i >= pattern.size()) {
                return false;
            }

            auto pos = sv.find(' ', j);
            string_view key;
            if (pos == string_view::npos) {
                key = sv.substr(j);
                j = pos;
            }
            else {
                key = sv.substr(j, pos - j);
                j = pos + 1;
            }

            if (s2c.find(key) == s2c.end()) {
                if (c2s.find(pattern[i]) == c2s.end()) {
                    s2c[key] = pattern[i];
                    c2s[pattern[i]] = key;
                }
                else {
                    return false;
                }
            }
            else {
                if (s2c[key] != pattern[i]) {
                    return false;
                }
            }

            ++i;
        }   

        return pattern.size() == i;
    }
};