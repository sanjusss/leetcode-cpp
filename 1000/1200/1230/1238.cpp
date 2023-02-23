/*
 * @Author: sanjusss
 * @Date: 2023-02-23 12:55:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-23 13:08:51
 * @FilePath: \1000\1200\1230\1238.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> circularPermutation(int n, int start) {
//         vector<bool> used(1 << n);
//         used[start] = true;
//         vector<int> ans;
//         ans.push_back(start);
//         while (ans.size() != (1 << n)) {
//             int p = ans.back();
//             for (int i = 0; i < n; ++i) {
//                 int c = p;
//                 if (p & (1 << i)) {
//                     c -= 1 << i;
//                 }
//                 else {
//                     c += 1 << i;
//                 }

//                 if (used[c]) {
//                     continue;
//                 }

//                 used[c] = true;
//                 ans.push_back(c);
//                 break;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < n; ++i) {
            for (int j = ans.size() - 1; j >= 0; --j) {
                ans.push_back(ans[j] | (1 << i));
            }
        }

        int offset = 0; 
        while (ans[offset] != start) {
            ans.push_back(ans[offset++]);
        }

        int len = 1 << n;
        for (int i = 0; i < len; ++i) {
            ans[i] = ans[i + offset];
        }

        ans.resize(len);
        return ans;
    }
};