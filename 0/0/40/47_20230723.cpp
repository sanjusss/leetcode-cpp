#include "leetcode.h"

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         deque<int> rights;
//         for (int i : height) {
//             while (!rights.empty() && rights.back() < i) {
//                 rights.pop_back();
//             }

//             rights.push_back(i);
//         }

//         rights.push_back(0);

//         int left = 0;
//         int ans = 0;
//         for (int i : height) {
//             left = max(i, left);
//             if (rights.front() == i) {
//                 rights.pop_front();
//             }

//             ans += max(0, min(left, rights.front()) - i);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = (int)height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(height[left], leftMax);
                ans += leftMax - height[left];
                ++left;
            } 
            else {
                rightMax = max(height[right], rightMax);
                ans += rightMax - height[right];
                --right;
            }
        }

        return ans;
    }
};