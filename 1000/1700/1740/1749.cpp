#include "leetcode.h"

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0;
        int ans = 0;
        int minSum = 0;
        int maxSum = 0;
        for (int i : nums) {
            sum += i;
            ans = max(ans, abs(sum - minSum));
            ans = max(ans, abs(sum - maxSum));
            minSum = min(sum, minSum);
            maxSum = max(sum, maxSum);
        }

        return ans;
    }
};

TEST(&Solution::maxAbsoluteSum)