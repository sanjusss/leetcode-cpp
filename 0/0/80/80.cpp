#include "leetcode.h"

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int cur = 0;
//         int prev = INT_MAX;
//         int prevLength = 0;
//         for (int i : nums) {
//             if (prev == i) {
//                 if (++prevLength <= 2) {
//                     nums[cur++] = i;
//                 }
//             }
//             else {
//                 prevLength = 1;
//                 nums[cur++] = i;
//             }

//             prev = i;
//         }

//         return cur;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }

        int slow = 2;
        int fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow++] = nums[fast];
            }

            ++fast;
        }

        return slow;
    }
};