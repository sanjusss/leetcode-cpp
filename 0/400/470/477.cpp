/*
 * @Author: sanjusss
 * @Date: 2021-05-28 08:20:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-28 08:27:48
 * @FilePath: \0\400\470\477.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int totalHammingDistance(vector<int>& nums) {
//         vector<vector<int>> sums(2, vector<int>(32));
//         int ans = 0;
//         for (int i : nums) {
//             for (int j = 0; j < 32; ++j) {
//                 int bit = (i & (1 << j)) ? 1 : 0;
//                 ans += sums[1 - bit][j];
//                 ++sums[bit][j];
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int cnt1 = 0;
            for (int j : nums) {
                if (j & (1 << i)) {
                    ++cnt1;
                }
            }

            ans += cnt1 * (n - cnt1);
        }

        return ans;
    }
};

TEST(&Solution::totalHammingDistance)