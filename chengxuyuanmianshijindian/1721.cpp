#include "leetcode.h"

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> left(n);
//         for (int i = 1; i < n; ++i) {
//             left[i] = max(left[i - 1], height[i - 1]);
//         }

//         vector<int> right(n);
//         for (int i = n - 2; i >= 0; --i) {
//             right[i] = max(right[i + 1], height[i + 1]);
//         }

//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             int h = min(left[i], right[i]);
//             if (h > height[i]) {
//                 ans += h - height[i];
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            }
            else {
                ans += rightMax - height[right];
                --right;
            }
        }

        return ans;
    }
};

TEST(&Solution::trap)