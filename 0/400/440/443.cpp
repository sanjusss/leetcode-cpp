/*
 * @Author: sanjusss
 * @Date: 2021-08-22 08:50:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 09:14:02
 * @FilePath: \0\400\440\443.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 0) {
            return 0;
        }

        int cur = 1;
        int prev = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != n && chars[i] == chars[prev]) {
                continue;
            }

            int cnt = i - prev;
            if (cnt > 1) {
                int start = cur;
                while (cnt > 0) {
                    chars[cur++] = (cnt % 10) + '0';
                    cnt /= 10;
                }

                reverse(chars.begin() + start, chars.begin() + cur);
            }

            prev = i;
            if (i < n) {
                chars[cur++] = chars[i];
            }
        }

        return cur;
    }
};

TEST(&Solution::compress)