/*
 * @Author: sanjusss
 * @Date: 2021-02-28 10:28:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-28 11:01:54
 * @FilePath: \C\C200\C230\C230\2.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
//         int m = toppingCosts.size();
//         set<int> toppings;
//         dfs(toppingCosts, m, 0, toppings, 0);
//         int ans = baseCosts[0];
//         for (int i : baseCosts) {
//             auto pos = toppings.upper_bound(target - i);
//             int a = (pos == toppings.end() ? *prev(pos) : *pos) + i;
//             if (pos != toppings.begin()) {
//                 int b = *prev(pos) + i;
//                 if (abs(target - a) >= abs(target - b)) {
//                     a = b;
//                 }
//             }

//             if (a == target) {
//                 return target;
//             }
//             else if (abs(target - a) < abs(target - ans)) {
//                 ans = a;
//             }
//             else if (abs(target - a) == abs(target - ans)) {
//                 ans = min(a, ans);
//             }
//         }

//         return ans;
//     }

// private:
//     void dfs(const vector<int>& toppingCosts, int m, int mi, set<int>& toppings, int cur) {
//         if (mi == m) {
//             toppings.insert(cur);
//             return;
//         }

//         for (int i = 0; i <= 2; ++i) {
//             dfs(toppingCosts, m, mi + 1, toppings, cur + i * toppingCosts[mi]);
//         }
//     }
// };

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        const int maxCost = min(20000, *max_element(baseCosts.begin(), baseCosts.end()) + 2 * accumulate(toppingCosts.begin(), toppingCosts.end(), 0));
        vector<bool> can(maxCost + 1);
        for (int i : baseCosts) {
            can[i] = true;
        }

        for (int i = 0; i < 2; ++i) {
            for (int j : toppingCosts) {
                for (int k = maxCost; k >= j; --k) {
                    can[k] = can[k] || can[k - j];
                }
            }
        }

        int left = min(target, maxCost);
        int right = min(target, maxCost);
        while (left > 0 || right <= maxCost) {
            if (left > 0) {
                if (can[left]) {
                    return left;
                }

                --left;
            }

            if (right <= maxCost) {
                if (can[right]) {
                    return right;
                }

                ++right;
            }
        }
        
        return -1;
    }
};

TEST(&Solution::closestCost)