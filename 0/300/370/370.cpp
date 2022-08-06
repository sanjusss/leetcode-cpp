/*
 * @Author: sanjusss
 * @Date: 2022-08-02 08:37:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-02 09:02:24
 * @FilePath: \0\300\370\370.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
//         vector<int> adds(length * 2);
//         for (auto& u : updates) {
//             int left = u[0] + length;
//             int right = u[1] + length;
//             int v = u[2];
//             while (left <= right) {
//                 if (left % 2 == 1) {
//                     adds[left++] += v;
//                 }

//                 if (right % 2 == 0) {
//                     adds[right--] += v;
//                 }

//                 left /= 2;
//                 right /= 2;
//             }
//         }

//         for (int i = 2; i < length * 2; ++i) {
//             adds[i] += adds[i / 2];
//         }

//         copy(adds.begin() + length, adds.end(), adds.begin());
//         adds.resize(length);
//         return adds;
//     }
// };

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length);
        for (auto& u : updates) {
            ans[u[0]] += u[2];
            if (u[1] + 1 < length) {
                ans[u[1] + 1] -= u[2];
            }
        }

        for (int i = 1; i < length; ++i) {
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};