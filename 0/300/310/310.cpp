/*
 * @Author: sanjusss
 * @Date: 2022-04-06 10:17:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-06 16:39:08
 * @FilePath: \0\300\310\310.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> conns(n);
//         for (auto& e : edges) {
//             conns[e[0]].push_back(e[1]);
//             conns[e[1]].push_back(e[0]);
//         }

//         unordered_map<int64_t, int> dp;
//         function<int(int, int)> dfs = [&](int i, int parent) -> int {
//             int64_t key = (((int64_t)i) << 32) | parent; 
//             if (dp.count(key)) {
//                 return dp[key];
//             }

//             int h = 0;
//             for (int j : conns[i]) {
//                 if (j != parent) {
//                     h = max(h, dfs(j, i));
//                 }
//             }

//             dp[key] = ++h;
//             return h;
//         };

//         vector<int> ans;
//         int height = n;
//         for (int i = 0; i < n; ++i) {
//             int h = dfs(i, n);
//             if (h < height) {
//                 ans.clear();
//                 ans.push_back(i);
//                 height = h;
//             }
//             else if (h == height) {
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> conns(n);
//         for (auto& e : edges) {
//             conns[e[0]].push_back(e[1]);
//             conns[e[1]].push_back(e[0]);
//         }

//         vector<pair<int, int>> heights2(n);        
//         vector<unordered_map<int, int>> subHeights(n);
//         function<int(int, int)> dfs = [&](int cur, int parent) -> int {
//             int size = conns[cur].size();
//             auto& [f, s] = heights2[cur];
//             auto& sub = subHeights[cur];
//             for (int i = 0; i < size; ++i) {
//                 int next = conns[cur][i];
//                 if (next == parent) {
//                     continue;
//                 }
                
//                 int h = dfs(next, cur);
//                 sub[next] = h;
//                 if (h > f) {
//                     s = f;
//                     f = h;
//                 }
//                 else if (h > s) {
//                     s = h;
//                 }
//             }

//             return f + 1;
//         };

//         dfs(0, n);
//         vector<int> heights(n);
//         stack<pair<int, int>> s;
//         s.emplace(0, n);
//         while (!s.empty()) {
//             auto [cur, parent] = s.top();
//             s.pop();
//             for (int next : conns[cur]) {
//                 if (next != parent) {
//                     s.emplace(next, cur);
//                 }
//             }

//             heights[cur] = heights2[cur].first + 1;
//             if (parent == n) {
//                 continue;
//             }

//             int parenth = 0;
//             if (subHeights[parent][cur] == heights2[parent].first) {
//                 parenth = heights2[parent].second + 1;
//             }
//             else {
//                 parenth = heights2[parent].first + 1;
//             }

//             heights[cur] = max(heights[cur], parenth + 1);
//             subHeights[cur][parent] = parenth;
//             if (parenth > heights2[cur].first) {
//                 heights2[cur].second = heights2[cur].first;
//                 heights2[cur].first = parenth;
//             }
//             else if (parenth > heights2[cur].second) {
//                 heights2[cur].second = parenth;
//             }
//         }

//         int low = *min_element(heights.begin(), heights.end());
//         vector<int> ans;
//         for (int i = 0; i < n; ++i) {
//             if (heights[i] == low) {
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> conns(n);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
        }

        vector<pair<int, int>> subHeights(n);
        queue<tuple<int, int, int>> q;
        function<int(int, int)> dfs = [&](int cur, int parent) -> int {
            int size = conns[cur].size();
            auto& [f, s] = subHeights[cur];
            for (int i = 0; i < size; ++i) {
                int next = conns[cur][i];
                if (next == parent) {
                    continue;
                }
                
                auto& [_1, _2, h] = q.emplace(next, cur, 0);
                h = dfs(next, cur);
                if (h > f) {
                    s = f;
                    f = h;
                }
                else if (h > s) {
                    s = h;
                }

            }

            return f + 1;
        };

        vector<int> heights(n);
        heights[0] = dfs(0, n);
        while (!q.empty()) {
            auto [cur, parent, h] = q.front();
            q.pop();
            auto& [pf, ps] = subHeights[parent];
            auto& [cf, cs] = subHeights[cur];
            int subParent = (pf == h ? ps : pf) + 1;
            if (subParent > cf) {
                cs = cf;
                cf = subParent;
            }
            else if (subParent > cs) {
                cs = subParent;
            }

            heights[cur] = cf + 1;
        }

        int low = *min_element(heights.begin(), heights.end());
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (heights[i] == low) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::findMinHeightTrees)