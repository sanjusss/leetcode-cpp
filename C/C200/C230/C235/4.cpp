/*
 * @Author: sanjusss
 * @Date: 2021-04-04 10:29:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-04 12:21:26
 * @FilePath: \C\C200\C230\C235\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countDifferentSubsequenceGCDs(vector<int>& nums) {
//         unordered_set<int> ans;
//         vector<int> temp;
//         for (int i : nums) {
//             if (ans.find(i) != ans.end()) {
//                 continue;
//             }

//             for (int j : ans) {
//                 temp.push_back(gcd(i, j));
//             }

//             for (int j : temp) {
//                 ans.insert(j);
//             }

//             ans.insert(i);
//             temp.clear();
//         }

//         return ans.size();
//     }

// private:
//     int gcd(int a, int b) {
//         int res = b;
//         while (a % b != 0) {
//             res = a % b;
//             a = b;
//             b = res;
//         }

//         return res;
//     }
// };

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        static const int maxN = 2e5;
        vector<bool> exist(maxN + 1);
        for (int i : nums) {
            exist[i] = true;
        }

        int ans = 0;
        for (int i = 1; i <= maxN; ++i) {
            int  g = 0;
            for (int j = 1; i * j <= maxN; ++j) {
                if (exist[i * j]) {
                    g = gcd(g, j);//如果i是最大公约数，那么j之间应该互质
                }
            }

            if (g == 1) { //i 是一个最大公约数
                ++ans;
            }
        }

        return ans;
    }

private:
    int gcd(int a, int b) {
        int res = b;
        while (a % b != 0) {
            res = a % b;
            a = b;
            b = res;
        }

        return res;
    }
};

TEST(&Solution::countDifferentSubsequenceGCDs)