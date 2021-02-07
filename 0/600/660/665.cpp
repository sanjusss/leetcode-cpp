#include "leetcode.h"

// class Solution {
// public:
//     bool checkPossibility(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 1) {
//             return true;
//         }

//         int prev2;
//         int prev1;
//         bool changed;
//         if (nums[0] > nums[1]) {
//             changed = true;
//             prev1 = nums[1];
//             prev2 = nums[1];
//         }
//         else {
//             changed = false;
//             prev1 = nums[1];
//             prev2 = nums[0];
//         }

//         for (int i = 2; i < n; ++i) {
//             if (nums[i] >= prev1) {
//                 prev2 = prev1;
//                 prev1 = nums[i];
//             }
//             else {
//                 if (changed) {
//                     return false;
//                 }
//                 else {
//                     changed = true;
//                     if (nums[i] >= prev2) {
//                         prev1 = nums[i];
//                     }
//                 }
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        int end = nums.size() - 1;
        for (int i = 0; i < end; ++i) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            if (changed) {
                return false;
            }

            changed = true;
            if (i > 0 && nums[i - 1] > nums[i + 1]) {
                nums[i + 1] = nums[i];
            }
            else {
                nums[i] = nums[i + 1];
            }
        }

        return true;
    }
};

TEST(&Solution::checkPossibility)