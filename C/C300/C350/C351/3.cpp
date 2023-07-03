#include "leetcode.h"

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        static const int64_t mod = 1e9 + 7;
        int64_t ans = 1;
        int n = nums.size();
        int pre = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 1) {
                continue;
            }

            if (pre >= 0) {
                ans *= i - pre;
                ans %= mod;
            }

            pre = i;
        }

        if (pre < 0) {
            return 0;
        }
        else {
            return ans;
        }
    }
};

TEST(&Solution::numberOfGoodSubarraySplits)