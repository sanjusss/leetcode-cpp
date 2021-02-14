#include "leetcode.h"

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            int ops = 0;
            for (int i : nums) {
                ops += (i - 1) / mid;
            }

            if (ops <= maxOperations) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

TEST(&Solution::minimumSize)