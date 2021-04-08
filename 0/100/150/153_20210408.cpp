#include "leetcode.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() <= nums.back()) {
            return nums.front();
        }

        int leftMin = nums.front();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= leftMin) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};

TEST(&Solution::findMin)