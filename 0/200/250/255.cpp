/*
 * @Author: sanjusss
 * @Date: 2022-02-12 11:11:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-12 12:11:44
 * @FilePath: \0\200\250\255.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool verifyPreorder(vector<int>& preorder) {
//         int n = preorder.size();
//         vector<int> bigger(n);
//         stack<int> s;
//         for (int i = n - 1; i >= 0; --i) {
//             while (!s.empty() && preorder[s.top()] < preorder[i]) {
//                 s.pop();
//             }

//             if (s.empty()) {
//                 bigger[i] = INT_MAX;
//             }
//             else {
//                 bigger[i] = s.top();
//             }

//             s.push(i);
//         }

//         function<bool(int, int, int, int)> dfs = [&preorder, &bigger, &dfs](int left, int right, int minE, int maxE) -> bool {
//             if (left > right) {
//                 return true;
//             }
//             else if (preorder[left] <= minE || preorder[left] >= maxE) {
//                 return false;
//             }
            
//             int mid = min(bigger[left], right + 1);
//             return dfs(left + 1, mid - 1, minE, preorder[left]) && dfs(mid, right, preorder[left], maxE);
//         };
//         return dfs(0, n - 1, INT_MIN, INT_MAX);
//     }
// };

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int maxPre = INT_MIN;
        for (int i : preorder) {
            if (i < maxPre) {
                return false;
            }

            while (!s.empty() && s.top() < i) {
                maxPre = s.top();
                s.pop();
            }

            s.push(i);
        }

        return true;
    }
};