/*
 * @Author: sanjusss
 * @Date: 2021-12-29 08:57:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-29 09:08:29
 * @FilePath: \1000\1900\1990\1995.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countQuadruplets(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 for (int k = j + 1; k < n; ++k) {
//                     for (int l = k + 1; l < n; ++l) {
//                         if (nums[i] + nums[j] + nums[k] == nums[l]) {
//                             ++ans;
//                         }
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int b = n - 3; b > 0; --b) {
            int c = b + 1;
            for (int d = c + 1; d < n; ++d) {
                ++cnt[nums[d] - nums[c]];
            }

            for (int a = 0; a < b; ++a) {
                ans += cnt[nums[a] + nums[b]];
            }
        }

        return ans;
    }
};