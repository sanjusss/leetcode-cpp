#include "leetcode.h"

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        int ans = 0;
        int64_t pre = 0;
        for (int i : usageLimits) {
            pre += i;
            if (pre >= ans + 1) {
                pre -= ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::maxIncreasingGroups)