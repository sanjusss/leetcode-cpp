/*
 * @Author: sanjusss
 * @Date: 2023-01-10 10:06:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-10 11:04:31
 * @FilePath: \0\700\750\753.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     string crackSafe(int n, int k) {
//         int mod = pow(10, n - 1);
//         vector<bool> visit(mod * 10);
//         string ans(n - 1, '0');
//         int target = pow(k, n) + n - 1;
//         function<bool(int)> dfs = [&](int node) {
//             for (int i = 0; i < k; ++i) {
//                 int v = node * 10 + i;
//                 if (visit[v]) {
//                     continue;
//                 }

//                 ans.push_back('0' + i);
//                 visit[v] = true;
//                 if (dfs(v % mod)) {
//                     return true;
//                 }
//                 else {
//                     visit[v] = false;
//                     ans.pop_back();
//                 }
//             }

//             return ans.size() == target;
//         };
//         dfs(0);
//         return ans;
//     }
// };

class Solution {
public:
    string crackSafe(int n, int k) {
        int mod = pow(10, n - 1);
        vector<int> next(mod, k);
        string ans(n - 1, '0');
        int node = 0;
        do {
            --next[node];
            ans.push_back('0' + next[node]);
            int v = node * 10 + next[node];
            node = v % mod;
        } while (next[0] != 0);
        return ans;
    }
};