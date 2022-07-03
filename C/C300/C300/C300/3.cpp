/*
 * @Author: sanjusss
 * @Date: 2022-07-03 11:04:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-03 11:18:52
 * @FilePath: \C\C300\C300\C300\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        if (delay >= forget) {
            if (n <= forget) {
                return 1;
            }
            else {
                return 0;
            }
        }

        static constexpr int64_t mod = 1e9 + 7;
        vector<int64_t> remove(n);
        vector<int64_t> add(n);
        int64_t knows = 0;
        int64_t canShare = 0;
        for (int i = 0; i < n; ++i) {
            canShare += add[i] - remove[i] + mod;
            canShare %= mod;
            int64_t newKnows = i == 0 ? 1 : canShare;
            if (i + delay < n) {
                add[i + delay] = newKnows;
            }

            if (i + forget < n) {
                remove[i + forget] = newKnows;
            }

            knows += newKnows - remove[i] + mod;
            knows %= mod;
        }

        return knows;
    }
};