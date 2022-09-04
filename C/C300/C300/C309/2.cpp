/*
 * @Author: sanjusss
 * @Date: 2022-08-21 10:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-04 10:45:58
 * @FilePath: \C\C300\C300\C309\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        static constexpr int mod = 1e9 + 7;
        int dis = abs(startPos - endPos);
        if (dis > k) {
            return 0;
        }

        int total = 2 * k + 1;
        vector<int> cur(total);
        vector<int> prev(total);
        cur[k] = 1;
        for (int i = 1; i <= k; ++i) {
            swap(cur, prev);
            fill(cur.begin(), cur.end(), 0);
            for (int j = 0; j < total; ++j) {
                if (j - 1 >= 0) {
                    cur[j] += prev[j - 1];
                }

                if (j + 1 < total) {
                    cur[j] += prev[j + 1];
                }

                cur[j] %= mod;
            }
        }
        
        return cur[k + dis];
    }
};