/*
 * @Author: sanjusss
 * @Date: 2022-05-09 09:04:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-09 09:12:37
 * @FilePath: \0\900\940\942.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> diStringMatch(string s) {
//         int n = s.size();
//         int left = 0;
//         int right = 0;
//         vector<int> ans(n + 1);
//         for (int i = 0; i < n; ++i) {
//             if (s[i] == 'I') {
//                 ans[i + 1] = ++right;
//             }
//             else {
//                 ans[i + 1] = --left;
//             }
//         }

//         for (auto& i : ans) {
//             i -= left;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int left = 0;
        int right = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                ans[i] = left++;
            }
            else {
                ans[i] = right--;
            }
        }

        ans[n] = left;
        return ans;
    }
};