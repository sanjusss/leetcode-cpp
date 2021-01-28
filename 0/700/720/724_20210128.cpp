#include "leetcode.h"

// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) {
//             return -1;
//         }

//         vector<int> sums(n);
//         sums[0] = nums[0];
//         for (int i = 1; i < n; ++i) {
//             sums[i] = sums[i - 1] + nums[i];
//         }

//         for (int i = 0; i < n; ++i) {
//             if (sums[i] - nums[i] == sums[n - 1] - sums[i]) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            else {
                left += nums[i];
            }
        }

        return -1;
    }
};

TEST(Solution::pivotIndex)