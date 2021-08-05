/*
 * @Author: sanjusss
 * @Date: 2021-08-05 10:08:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-05 11:19:48
 * @FilePath: \0\800\800\802.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<vector<int>> from(n);
//         vector<int> outs(n);
//         for (int i = 0; i < n; ++i) {
//             for (int j : graph[i]) {
//                 if (i != j) {
//                     from[j].push_back(i);
//                 }

//                 ++outs[i];
//             }
//         }

//         queue<int> q;
//         vector<int> ans;
//         for (int i = 0; i < n; ++i) {
//             if (outs[i] == 0) {
//                 q.push(i);
//                 ans.push_back(i);
//             }
//         }
        
//         while (!q.empty()) {
//             int i = q.front();
//             q.pop();
//             for (int j : from[i]) {
//                 if (--outs[j] == 0) {
//                     ans.push_back(j);
//                     q.push(j);
//                 }
//             }
//         }

//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);//0未开始，1在堆栈中或已有环，2安全节点
        function<bool(int)> isSafe = [&](int i) -> bool {
            if (colors[i] > 0) {
                return colors[i] == 2;
            }

            colors[i] = 1;
            for (int j : graph[i]) {
                if (!isSafe(j)) {
                    return false;
                }
            }

            colors[i] = 2;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (isSafe(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

TEST(&Solution::eventualSafeNodes)