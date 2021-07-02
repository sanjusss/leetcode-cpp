/*
 * @Author: sanjusss
 * @Date: 2021-07-02 08:31:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-02 08:41:21
 * @FilePath: \1000\1800\1830\1833.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         sort(costs.begin(), costs.end());
//         int sum = 0;
//         int ans = 0;
//         for (int i : costs) {
//             sum += i;
//             if (coins < sum) {
//                 break;
//             }
//             else {
//                 ++ans;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxI = *max_element(costs.begin(), costs.end());
        vector<int> cnt(maxI + 1);
        for (int i : costs) {
            ++cnt[i];
        }

        int ans = 0;
        for (int i = 1; i <= maxI && coins >= i; ++i) {
            int f = min(coins / i, cnt[i]);
            ans += f;
            coins -= f * i;
        }

        return ans;
    }
};