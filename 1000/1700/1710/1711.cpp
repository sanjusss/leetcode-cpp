/*
 * @Author: sanjusss
 * @Date: 2021-07-07 08:19:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-07 08:40:38
 * @FilePath: \1000\1700\1710\1711.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        static constexpr int64_t mod = 1e9 + 7;
        unordered_map<int, int64_t> cnt;
        for (int i : deliciousness) {
            ++cnt[i];
        }

        vector<int> pow2(22);
        pow2[0] = 1;
        for (int i = 1; i <= 21; ++i) {
            pow2[i] = pow2[i - 1] << 1;
        }

        int64_t ans = 0;
        for (auto& [i, c] : cnt) {
            for (auto p = lower_bound(pow2.begin(), pow2.end(), i * 2); p != pow2.end(); ++p) {
                auto r = cnt.find(*p - i);
                if (r == cnt.end()) {
                    continue;
                }

                if (r->first == i) {
                    ans = (ans  + c * (c - 1) / 2) % mod;
                }
                else {
                    ans = (ans + r->second * c) % mod;
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::countPairs)