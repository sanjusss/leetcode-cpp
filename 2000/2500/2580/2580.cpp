/*
 * @Author: sanjusss
 * @Date: 2024-03-27 09:00:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-27 09:28:14
 * @FilePath: \2000\2500\2580\2580.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        map<int, int> rs;
        for (auto& r : ranges) {
            int start = r[0];
            int stop = r[1];
            auto iter = rs.upper_bound(start);
            if (iter != rs.begin()) {
                auto pre = prev(iter);
                if (pre->second >= start) {
                    start = pre->first;
                    stop = max(stop, pre->second);
                    rs.erase(pre);
                }
            }

            while (iter != rs.end() && iter->first <= stop) {
                stop = max(stop, iter->second);
                iter = rs.erase(iter);
            }

            rs[start] = stop;
        }

        static const int64_t mod = 1e9 + 7;
        int64_t ans = 1;
        int64_t t = rs.size();
        int64_t f = 2;
        while (t > 0) {
            if (t & 1) {
                ans *= f;
                ans %= mod;
            }

            f *= f;
            f %= mod;
            t >>= 1;
        }

        return ans;
    }
};

TEST(&Solution::countWays)