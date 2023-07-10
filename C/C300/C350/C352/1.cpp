#include "leetcode.h"

// class Solution {
// public:
//     int longestAlternatingSubarray(vector<int>& nums, int threshold) {
//         int ans = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             if (nums[i] % 2 != 0 || nums[i] > threshold) {
//                 continue;
//             }

//             ans = max(ans, 1);
//             for (int j = i + 1; j < n && nums[j] <= threshold && nums[j] % 2 != nums[j - 1] % 2; ++j) {
//                 ans = max(ans, j - i + 1);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > threshold || nums[i] % 2 != 0) {
                continue;
            }

            int len = 0;
            do {
                ++i;
                ++len;
            } while (i < n && nums[i] <= threshold && nums[i - 1] % 2 != nums[i] % 2);
            --i;
            ans = max(ans, len);
        }

        return ans;
    }
};

TEST(&Solution::longestAlternatingSubarray)