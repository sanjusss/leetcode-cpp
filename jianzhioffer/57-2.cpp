/*
 * @Author: sanjusss
 * @Date: 2021-08-29 08:59:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 09:25:45
 * @FilePath: \jianzhioffer\57-2.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> findContinuousSequence(int target) {
//         vector<vector<int>> ans;
//         int t = target * 2;
//         for (int n = sqrt(t) - 1; n > 1; --n) {
//             if (t % n != 0 ) {
//                 continue;
//             }

//             int start = t / n - n + 1;
//             if (start % 2 != 0 || start == 0) {
//                 continue;
//             }

//             start /= 2;
//             ans.push_back({ start });
//             for (int j = 1; j < n; ++j) {
//                 ans.back().push_back(start + j);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int left = 1;
        int right = 2;
        while (left < right) {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                ans.push_back({ left });
                for (int i = left + 1; i <= right; ++i) {
                    ans.back().push_back(i);
                }

                ++left;
            }
            else if (sum > target) {
                ++left;
            }
            else {
                ++right;
            }
        }

        return ans;
    }
};