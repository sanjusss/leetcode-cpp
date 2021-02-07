#include "leetcode.h"

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= nums[i - 1]) {
                continue;
            }
            else if (x > 0) {
                return false;
            }
            else {
                x = i;
            }
        }

        if (x > 0) {
            return nums.front() >= nums.back();
        }
        else {
            return true;
        }
    }
};