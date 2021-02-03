#include "leetcode.h"

// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int ans = 0;
//         bool containsZero = false;
//         int len = 0;
//         int zeroPos = 0;
//         for (int i : nums) {
//             ++len;
//             if (i == 1) {
//                 if (!containsZero) {
//                     ++zeroPos;
//                 }
//             }
//             else {
//                 if (containsZero) {
//                     len -= zeroPos;
//                     zeroPos = len;
//                 }
//                 else {
//                     containsZero = true;
//                     ++zeroPos;
//                 }
//             }

//             ans = max(ans, len);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int containZero = 0;
        int oneOnly = 0;
        for (int i : nums) {
            if (i == 1) {
                ++oneOnly;
                ++containZero;
            }
            else {
                containZero = oneOnly + 1;
                oneOnly = 0;
            }

            ans = max(ans, containZero);
        }

        return ans;
    }
};

TEST(&Solution::findMaxConsecutiveOnes)