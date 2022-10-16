/*
 * @Author: sanjusss
 * @Date: 2022-10-07 14:58:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-07 15:15:47
 * @FilePath: \LCP\20221007\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        static constexpr uint64_t mod = 1e9 + 7;
        uint64_t left = 0;
        uint64_t right = 0;
        uint64_t n = flowers.size();
        unordered_map<int, int> state;
        uint64_t ans = 0;
        while (right < n) {
            ++state[flowers[right]];
            while (left < right && state[flowers[right]] > cnt) {
                --state[flowers[left++]];
            }

            ans += right - left + 1;
            ans %= mod;
            ++right;
        }

        return ans;
    }
};

TEST(&Solution::beautifulBouquet)