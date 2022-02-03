/*
 * @Author: sanjusss
 * @Date: 2022-02-01 21:34:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-01 21:52:20
 * @FilePath: \1000\1700\1760\1763.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string longestNiceSubstring(string s) {
        string_view sv = s;
        string_view ans;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int l = 0;
            int u = 0;
            int diff = 0;
            int b;
            for (int j = i; j < n; ++j) {
                if (sv[j] >= 'a') {
                    b = 1 << (sv[j] - 'a');
                    if (!(l & b)) {
                        if (u & b) {
                            --diff;
                        }
                        else {
                            ++diff;
                        }
                    }

                    l |= b;
                }
                else {
                    b = 1 << (sv[j] - 'A');
                    if (!(u & b)) {
                        if (l & b) {
                            --diff;
                        }
                        else {
                            ++diff;
                        }
                    }

                    u |= b;
                }

                if (diff == 0 && j - i + 1 > ans.size()) {
                    ans = sv.substr(i, j - i + 1);
                }
            }
        }

        return string(ans);
    }
};