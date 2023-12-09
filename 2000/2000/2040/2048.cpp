/*
 * @Author: sanjusss
 * @Date: 2023-12-09 22:37:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-09 23:02:09
 * @FilePath: \2000\2000\2040\2048.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int cnt[10];
        while (true) {
            ++n;
            memset(cnt, 0, sizeof(cnt));
            for (int v = n; v > 0; v /= 10) {
                cnt[v % 10] += 1;
            }

            bool success = true;
            for (int i = 0; i < 10; ++i) {
                if (cnt[i] != i && cnt[i] != 0) {
                    success = false;
                    break;
                }
            }

            if (success) {
                return n;
            }
        }

        return -1;
    }
};