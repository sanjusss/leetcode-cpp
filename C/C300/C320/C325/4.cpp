/*
 * @Author: sanjusss
 * @Date: 2022-12-25 10:25:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-25 12:13:15
 * @FilePath: \C\C300\C320\C325\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    static constexpr int64_t mod = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        if (accumulate(nums.begin(), nums.end(), 0ll) < k * 2) {
            return 0;
        }

        // sort(nums.begin(), nums.end());
        int n = nums.size();
        int64_t ans = pow(2, n);
        vector<int64_t> dp(k, 2);
        for (int i : nums) {
            for (int j = k - 1; j >= i; --j) {
                dp[j] = (dp[j] + dp[j - i]) % mod;
            }
        }

        return (ans + mod - dp[k - 1]) % mod;
    }

private:
    int64_t pow(int64_t a, int64_t b) {
        a %= mod;
        int64_t ans = 1;
        while (b > 0) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }

        return ans;
    }
};

TEST(&Solution::countPartitions)