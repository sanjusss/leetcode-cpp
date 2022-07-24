/*
 * @Author: sanjusss
 * @Date: 2022-07-17 09:58:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-17 10:15:58
 * @FilePath: \0\500\560\565.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int arrayNesting(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> width(n);
//         for (int i = 0; i < n; ++i) {
//             if (width[i] > 0) {
//                 continue;
//             }

//             int j = i;
//             do {
//                 width[nums[j]] = width[j] + 1;
//                 j = nums[j];
//             } while (j != i);
//         }

//         return *max_element(width.begin(), width.end());
//     }
// };

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == n) {
                continue;
            }

            int cnt = 0;
            int j = i;
            while (nums[j] < n) {
                ++cnt;
                int next = nums[j];
                nums[j] = n;
                j = next;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};

TEST(&Solution::arrayNesting)