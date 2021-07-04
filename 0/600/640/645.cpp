/*
 * @Author: sanjusss
 * @Date: 2021-07-04 09:36:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-04 09:54:53
 * @FilePath: \0\600\640\645.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> cnt(n + 1);
//         for (int i : nums) {
//             ++cnt[i];
//         }

//         vector<int> ans(2);
//         for (int i = 1; i <= n; ++i) {
//             if (cnt[i] == 0) {
//                 ans[1] = i;
//             }
//             else if (cnt[i] == 2) {
//                 ans[0] = i;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        for (int i : nums) {
            x ^= i;
        }

        for (int i = 1; i <= n; ++i) {
            x ^= i;
        }

        int lowBit = x & (-x);
        int a = 0;
        int b = 0;
        for (int i : nums) {
            if (i & lowBit) {
                a ^= i;
            }
            else {
                b ^= i;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (i & lowBit) {
                a ^= i;
            }
            else {
                b ^= i;
            }
        }

        vector<int> ans(2);
        for (int i : nums) {
            if (i == a) {
                ans[0] = a;
                ans[1] = b;
                break;
            }
            else if (i == b) {
                ans[0] = b;
                ans[1] = a;
                break;
            }
        }

        return ans;
    }
};

TEST(&Solution::findErrorNums)