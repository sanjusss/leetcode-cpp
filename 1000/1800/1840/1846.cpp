/*
 * @Author: sanjusss
 * @Date: 2021-07-15 08:16:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-15 08:25:22
 * @FilePath: \1000\1800\1840\1846.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         int prev = 0;
//         for (int i : arr) {
//             prev = min(prev + 1, i);
//         }

//         return prev;
//     }
// };

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n + 1);
        for (int i : arr) {
            ++cnt[min(i, n)];
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans + cnt[i], i);
        }

        return ans;
    }
};

TEST(&Solution::maximumElementAfterDecrementingAndRearranging)