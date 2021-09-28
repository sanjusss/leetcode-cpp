/*
 * @Author: sanjusss
 * @Date: 2021-09-27 21:07:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-27 21:42:10
 * @FilePath: \0\600\630\639.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numDecodings(string s) {
        static constexpr int64_t mod = 1e9 + 7;
        int64_t cur = 1;
        int64_t prev = 0;
        int m = s.size() - 1;
        for (int i = m; i >= 0; --i) {
            int64_t next = 0;
            // 后一位的0只能和当前位结合
            if (i < m && s[i + 1] == '0') {
                if (s[i] == '*') {
                    next += 2 * prev;
                }
                else if (s[i] == '1' || s[i] == '2') {
                    next += prev;
                }
                else {
                    return 0;
                }
            }
            // 后一位不为0
            else if (s[i] == '*') {
                next += cur * 9;  // 1位数字
                if (i < m) {      // 2位数字
                    if (s[i + 1] == '*') {
                        next += 15 * prev;
                    }
                    else if (s[i + 1] > '6') {
                        next += prev;
                    }
                    else {
                        next += 2 * prev;
                    }
                }
            }
            else if (s[i] != '0') {  //当前数字不为0
                next += cur;         // 1位数字
                if (i < m) {         // 2位数字
                    if (s[i] == '1') {
                        if (s[i + 1] == '*') {
                            next += 9 * prev;
                        }
                        else {
                            next += prev;
                        }
                    }
                    else if (s[i] == '2') {
                        if (s[i + 1] == '*') {
                            next += 6 * prev;
                        }
                        else if (s[i + 1] <= '6') {
                            next += prev;
                        }
                    }
                }
            }

            prev = cur;
            cur = next % mod;
        }

        return cur;
    }
};

TEST(&Solution::numDecodings)