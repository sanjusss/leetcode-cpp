/*
 * @Author: sanjusss
 * @Date: 2022-02-05 09:57:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-05 10:15:58
 * @FilePath: \0\100\160\161.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() == t.size()) {
            bool hasOne = false;
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    if (hasOne) {
                        return false;
                    }

                    hasOne = true;
                }
            }

            return hasOne;
        }
        else {
            if (s.size() > t.size()) {
                swap(s, t);
            }

            if (t.size() - s.size() != 1) {
                return false;
            }

            int skip = 0;
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                while (s[i] != t[i + skip]) {
                    if (++skip > 1) {
                        return false;
                    }
                }
            }

            return true;
        }
    }
};