#include "leetcode.h"

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            if (nums[right] <= threshold) {
                if (left < right && nums[right] % 2 == nums[right - 1] % 2) {
                    left = right;
                }
                
                while (left <= right && nums[left] % 2 != 0) {
                    ++left;
                }
            }
            else {
                left = right + 1;
            }

            ans = max(ans, right - left + 1);
            ++right;
        }

        return ans;
    }
};