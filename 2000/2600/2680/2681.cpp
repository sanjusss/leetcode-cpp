#include "leetcode.h"

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        static constexpr int64_t mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int64_t minsums = 0;
        int64_t pre = 0;
        int64_t ans = 0;
        for (int i : nums) {
            minsums *= 2;
            minsums += pre;
            minsums %= mod;
            ans += (((minsums + i) * i) % mod) * i;
            ans %= mod;
            pre = i;
        }

        return ans;
    }
};