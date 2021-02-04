#include "leetcode.h"

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int left = 0;
//         int right = 1;
//         int ans = 0;
//         while (right < n) {
//             if (height[right] >= height[left]) {
//                 int border = height[left++];
//                 while (left < right) {
//                     ans += border - height[left++];
//                 }
//             }

//             ++right;
//         }

//         int end = left;
//         left = n - 2;
//         right = n - 1;
//         while (left >= end) {
//             if (height[left] >= height[right]) {
//                 int border = height[right--];
//                 while (right > left) {
//                     ans += border - height[right--];
//                 }
//             }

//             --left;
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if (n == 0) {
//             return 0;
//         }

//         vector<int> leftMaxHeight(n);
//         for (int i = 1; i < n; ++i) {
//             leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i - 1]);
//         }

//         vector<int> rightMaxHeight(n);
//         for (int i = n - 2; i >= 0; --i) {
//             rightMaxHeight[i] = max(rightMaxHeight[i + 1], height[i + 1]);
//         }

//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             int border = min(leftMaxHeight[i], rightMaxHeight[i]);
//             if (border > height[i]) {
//                 ans += border - height[i];
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int ans = 0;
//         stack<int> s;
//         for (int i = 0; i < n; ++i) {
//             while (!s.empty() && height[i] >= height[s.top()]) {
//                 int j = s.top();
//                 s.pop();
//                 if (!s.empty()) {
//                     ans += (i - s.top() - 1) * (min(height[i], height[s.top()]) - height[j]);
//                 }
//             }

//             s.push(i);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    ans += leftMax - height[left];
                }

                ++left;
            }
            else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {
                    ans += rightMax - height[right];
                }

                --right;
            }
        }

        return ans;
    }
};

TEST(&Solution::trap)