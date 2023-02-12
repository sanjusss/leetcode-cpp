#include "leetcode.h"

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int64_t ans = 0;
        while (left < right) {
            ans += nums[right];
            int64_t b = 1;
            while (b <= nums[right]) {
                b *= 10;
            }

            ans += nums[left] * b;
            ++left;
            --right;
        }

        if (left == right) {
            ans += nums[left];
        }

        return ans;
    }
};