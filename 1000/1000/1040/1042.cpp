#include "leetcode.h"

// class Solution {
// public:
//     vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
//         vector<vector<int>> conns(n);
//         for (auto& p : paths) {
//             conns[p[0] - 1].push_back(p[1] - 1);
//             conns[p[1] - 1].push_back(p[0] - 1);
//         }

//         vector<int> ans(n);
//         stack<int> changed;
//         function<bool(int)> dfs = [&](int i) -> bool {
//             changed.push(i);
//             for (int c = 1; c <= 4; ++c) {
//                 ans[i] = c;
//                 bool success = true;
//                 for (int j : conns[i]) {
//                     if ((ans[j] == 0 && !dfs(j)) || ans[j] == c) {
//                         success = false;
//                         break;
//                     }
//                 }

//                 if (success) {
//                     return true;
//                 }

//                 while (changed.top() != i) {
//                     ans[changed.top()] = 0;
//                     changed.pop();
//                 }

//                 ans[i] = 0;
//             }

//             changed.pop();
//             return false;
//         };

//         for (int i = 0; i < n; ++i) {
//             if (ans[i] == 0) {
//                 dfs(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> conns(n);
        for (auto& p : paths) {
            conns[p[0] - 1].push_back(p[1] - 1);
            conns[p[1] - 1].push_back(p[0] - 1);
        }

        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            if (ans[i] != 0) {
                return;
            }

            vector<bool> used(5);
            for (int j : conns[i]) {
                used[ans[j]] = true;
            }

            for (int c = 1; c <= 4; ++c) {
                if (used[c]) {
                    continue;
                }

                ans[i] = c;
                break;
            }
        }

        return ans;
    }
};