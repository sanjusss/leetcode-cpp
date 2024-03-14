#include "leetcode.h"

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            if (ans >= nums[i]) {
                ans += nums[i];
            }
            else {
                ans = nums[i];
            }
        }

        return ans;
    }
};