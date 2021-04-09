#include "leetcode.h"

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int leftMin = nums.front();
//         int left = 0;
//         int right = nums.size() - 1;
//         while (left < right && leftMin == nums[right]) {
//             --right;
//         }

//         if (leftMin <= nums[right]) {
//             return leftMin;
//         }

//         while (left < right) {
//             int mid = (left + right) / 2;
//             if (nums[mid] >= leftMin) {
//                 left = mid + 1;
//             }
//             else {
//                 right = mid;
//             }
//         }

//         return nums[left];
//     }
// };

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]){
                right = mid;
            }
            else {
                --right;
            }
        }

        return nums[left];
    }
};

TEST(&Solution::findMin)