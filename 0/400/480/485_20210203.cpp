#include "leetcode.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int len = 0;
        for (int i : nums) {
            if (i == 1) {
                ans = max(ans, ++len);
            }
            else {
                len = 0;
            }
        }

        return ans;
    }
};

TEST(&Solution::findMaxConsecutiveOnes)