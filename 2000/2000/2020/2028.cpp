/*
 * @Author: sanjusss
 * @Date: 2022-03-27 09:57:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-27 10:05:56
 * @FilePath: \2000\2000\2020\2028.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
//         int sum = mean * (n + rolls.size());
//         sum -= accumulate(rolls.begin(), rolls.end(), 0);
//         if (sum < n || sum > n * 6) {
//             return {};
//         }

//         vector<int> ans;
//         while (n > 1) {
//             ans.push_back(sum / n);
//             sum -= sum / n;
//             --n;
//         }

//         ans.push_back(sum);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean * (n + rolls.size());
        sum -= accumulate(rolls.begin(), rolls.end(), 0);
        if (sum < n || sum > n * 6) {
            return {};
        }

        vector<int> ans(n, sum / n);
        for (int i = sum % n; i > 0; --i) {
            ++ans[i - 1];
        }

        return ans;
    }
};