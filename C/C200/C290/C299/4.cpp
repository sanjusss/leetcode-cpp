/*
 * @Author: sanjusss
 * @Date: 2022-06-26 10:29:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-26 15:48:33
 * @FilePath: \C\C200\C290\C299\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
//         int n = nums.size();
//         int total = 0;
//         for (int i : nums) {
//             total ^= i;
//         }

//         vector<vector<int>> conns(n);
//         for (auto& e : edges) {
//             conns[e[0]].push_back(e[1]);
//             conns[e[1]].push_back(e[0]);
//         }

//         int ans = INT_MAX;
//         vector<int> vals(n);
//         queue<pair<int, int>> q;
//         stack<pair<int, int>> s;
//         for (int i = 0; i < n; ++i) {
//             for (int j : conns[i]) {
//                 q.emplace(j, i);
//                 vals[j] = nums[j];
//                 while (!q.empty()) {
//                     auto [cur, prev] = q.front();
//                     q.pop();
//                     if (cur != j) {
//                         vals[j] ^= nums[cur];
//                         vals[cur] = -1;
//                     }

//                     for (int next : conns[cur]) {
//                         if (next != prev) {
//                             q.emplace(next, cur);
//                         }
//                     }
//                 }
//             }

//             vals[i] = nums[i];
//             for (int j : conns[i]) {
//                 s.emplace(j, i);
//                 vals[j]= -1;
//                 while (!s.empty()) {
//                     auto [cur, prev] = s.top();
//                     if (vals[cur] == -1) {
//                         vals[cur] = nums[cur];
//                         for (int next : conns[cur]) {
//                             if (next != prev) {
//                                 s.emplace(next, cur);
//                             }
//                         }
//                     }
//                     else {
//                         s.pop();
//                         vals[prev] ^= vals[cur];
//                         for (int ai : conns[i]) {
//                             if (ai == j) {
//                                 continue;
//                             }

//                             int a = vals[ai];
//                             int b = vals[cur];
//                             int c = total ^ a ^ b;
//                             ans = min(ans, max({ a, b, c }) - min({ a, b, c }));
//                         }
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
//         int total = 0;
//         for (int i : nums) {
//             total ^= i;
//         }

//         int n = nums.size();
//         vector<vector<int>> conns(n);
//         for (auto& e : edges) {
//             conns[e[0]].push_back(e[1]);
//             conns[e[1]].push_back(e[0]);
//         }

//         int root = 0;
//         for (int i = 1; i < n; ++i) {
//             if (conns[root].size() < conns[i].size()) {
//                 root = i;
//             }
//         }

//         vector<unordered_set<int>> all(n);
//         vector<int> vals(n, -1);
//         stack<pair<int, int>> s;
//         s.emplace(root, -1);
//         while (!s.empty()) {
//             auto [i, j] = s.top();
//             if (vals[i] == -1) {  // 子节点没有执行
//                 vals[i] = nums[i];
//                 for (int k : conns[i]) {
//                     if (k != j) {
//                         s.emplace(k, i);
//                     }
//                 }
//             }
//             else {  // 子节点已计算完毕
//                 s.pop();
//                 for (int k : conns[i]) {
//                     if (k != j) {
//                         vals[i] ^= vals[k];
//                         all[i].insert(k);
//                         for (int l : all[k]) {
//                             all[i].insert(l);
//                         }
//                     }
//                 }
//             }
//         }

//         int ans = INT_MAX;
//         int m = edges.size();
//         for (int i = 0; i < m; ++i) {
//             int ui = edges[i][0];  // 上层节点
//             int di = edges[i][1];  // 下层节点
//             if (all[di].count(ui)) {
//                 swap(ui, di);
//             }

//             for (int j = i + 1; j < m; ++j) {
//                 int uj = edges[j][0];  // 上层节点
//                 int dj = edges[j][1];  // 下层节点
//                 if (all[dj].count(uj)) {
//                     swap(uj, dj);
//                 }

//                 int a;
//                 int b;
//                 if (all[di].count(dj)) { // dj 是 di 的子节点
//                     a = vals[dj];
//                     b = vals[di] ^ vals[dj];
//                 }
//                 else if (all[dj].count(di)) { // di 是 dj 的子节点
//                     a = vals[di];
//                     b = vals[di] ^ vals[dj];
//                 }
//                 else { // 两者完全不相关
//                     a = vals[di];
//                     b = vals[dj];
//                 }

//                 int c = total ^ a ^ b;
//                 ans = min(ans, max({ a, b, c }) - min({ a, b, c }));
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int total = 0;
        for (int i : nums) {
            total ^= i;
        }

        int n = nums.size();
        vector<vector<int>> conns(n);
        vector<int> cnt(n);
        for (auto& e : edges) {
            conns[e[0]].push_back(e[1]);
            ++cnt[e[0]];
            conns[e[1]].push_back(e[0]);
            ++cnt[e[1]];
        }
        
        int root = 0;
        for (int i = 1; i < n; ++i) {
            if (conns[root].size() < conns[i].size()) {
                root = i;
            }
        }

        vector<vector<bool>> all(n, vector<bool>(n));
        vector<int> vals(n, -1);
        stack<pair<int, int>> s;
        s.emplace(root, -1);
        while (!s.empty()) {
            auto [i, j] = s.top();
            if (vals[i] == -1) {  // 子节点没有执行
                vals[i] = nums[i];
                for (int k : conns[i]) {
                    if (k != j) {
                        s.emplace(k, i);
                    }
                }
            }
            else {  // 子节点已计算完毕
                s.pop();
                for (int k : conns[i]) {
                    if (k != j) {
                        vals[i] ^= vals[k];
                        all[i][k] = true;
                        for (int l = 0; l < n; ++l) {
                            if (all[k][l]) {
                                all[i][l] = true;
                            }
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            int ui = edges[i][0];  // 上层节点
            int di = edges[i][1];  // 下层节点
            if (all[di][ui]) {
                swap(ui, di);
            }

            for (int j = i + 1; j < m; ++j) {
                int uj = edges[j][0];  // 上层节点
                int dj = edges[j][1];  // 下层节点
                if (all[dj][uj]) {
                    swap(uj, dj);
                }

                int a;
                int b;
                if (all[di][dj]) {  // dj 是 di 的子节点
                    a = vals[dj];
                    b = vals[di] ^ vals[dj];
                }
                else if (all[dj][di]) {  // di 是 dj 的子节点
                    a = vals[di];
                    b = vals[di] ^ vals[dj];
                }
                else {  // 两者完全不相关
                    a = vals[di];
                    b = vals[dj];
                }

                int c = total ^ a ^ b;
                ans = min(ans, max({ a, b, c }) - min({ a, b, c }));
            }
        }

        return ans;
    }
};

TEST(&Solution::minimumScore)