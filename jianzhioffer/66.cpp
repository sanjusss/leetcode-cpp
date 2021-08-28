/*
 * @Author: sanjusss
 * @Date: 2021-08-28 09:49:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-28 10:00:30
 * @FilePath: \jianzhioffer\66.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> constructArr(vector<int>& a) {
//         int n = a.size();
//         vector<int> lefts(n + 1);
//         vector<int> rights(n + 1);
//         lefts[0] = 1;
//         rights[n] = 1;
//         for (int i = 0; i < n; ++i) {
//             lefts[i + 1] = lefts[i] * a[i];
//             rights[n - 1 - i] = rights[n - i] * a[n - 1 - i];
//         }

//         vector<int> ans(n);
//         for (int i = 0; i < n; ++i) {
//             ans[i] = lefts[i] * rights[i + 1];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> b(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            b[i] = b[i + 1] * a[i + 1];
        } 

        int mul = 1;
        for (int i = 1; i < n; ++i) {
            mul *= a[i - 1];
            b[i] *= mul;
        }

        return b;
    }
};