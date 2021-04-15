#include "leetcode.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int cur = 0;
        int prev = 0;
        int cur1 = 0;
        int prev1 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tie(cur, prev) = make_pair(max(nums[i] + prev, cur), cur);
            if (i > 0) {
                tie(cur1, prev1) = make_pair(max(nums[i] + prev1, cur1), cur1);
            }
        }

        return max(cur1, prev);
    }
};

TEST(&Solution::rob)