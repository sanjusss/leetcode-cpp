/*
 * @Author: sanjusss
 * @Date: 2023-11-04 10:37:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-04 11:57:12
 * @FilePath: \2000\2000\2000\2003.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
//         int n = parents.size();
//         vector<unordered_set<int>> owns(n);
//         vector<int> mins(n);
//         for (int i = 0; i < n; ++i) {
//             owns[i].insert(nums[i]);
//             if (nums[i] == 1) {
//                 mins[i] = 2;
//             }
//             else {
//                 mins[i] = 1;
//             }
//         }

//         vector<int> outs(n);
//         for (int i : parents) {
//             if (i >= 0) {
//                 ++outs[i];
//             }
//         }

//         queue<int> q;
//         for (int i = 0; i < n; ++i) {
//             if (outs[i] == 0) {
//                 q.push(i);
//             }
//         }

//         while (!q.empty()) {
//             int i = q.front();
//             q.pop();
//             while (owns[i].count(mins[i])) {
//                 ++mins[i];
//             }

//             int p = parents[i];
//             if (p < 0) {
//                 continue;
//             }

//             mins[p] = max(mins[i], mins[p]);
//             if (owns[p].size() < owns[i].size()) {
//                 swap(owns[p], owns[i]);
//             }

//             owns[p].merge(owns[i]);
//             if (--outs[p] == 0) {
//                 q.push(p);
//             }
//         }

//         return mins;
//     }
// };

// class Solution {
// public:
//     vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
//         int n = parents.size();
//         vector<map<int, int>> owns(n);
//         vector<int> mins(n);
//         for (int i = 0; i < n; ++i) {
//             owns[i][nums[i]] = nums[i];
//             if (nums[i] == 1) {
//                 mins[i] = 2;
//             }
//             else {
//                 mins[i] = 1;
//             }
//         }

//         vector<int> outs(n);
//         for (int i : parents) {
//             if (i >= 0) {
//                 ++outs[i];
//             }
//         }

//         queue<int> q;
//         for (int i = 0; i < n; ++i) {
//             if (outs[i] == 0) {
//                 q.push(i);
//             }
//         }

//         while (!q.empty()) {
//             int i = q.front();
//             q.pop();
//             auto& cur = owns[i];
//             if (mins[i] >= cur.begin()->first) {
//                 mins[i] = cur.begin()->second + 1;
//             }

//             int p = parents[i];
//             if (p < 0) {
//                 continue;
//             }

//             mins[p] = max(mins[i], mins[p]);
//             auto& nxt = owns[p];
//             for (auto& [cb, ce] : cur) {
//                 int b = cb;
//                 int e = ce;
//                 auto iter = nxt.upper_bound(b);
//                 if (iter != nxt.end() && iter->first == e + 1) {
//                     e = iter->second;
//                     iter = nxt.erase(iter);
//                 }

//                 if (iter != nxt.begin()) {
//                     iter = prev(iter);
//                     if (iter->second + 1 == b) {
//                         b = iter->first;
//                         nxt.erase(iter);
//                     }
//                 }

//                 nxt[b] = e;
//             }

//             if (--outs[p] == 0) {
//                 q.push(p);
//             }
//         }

//         return mins;
//     }
// };

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> mins(n);
        int node = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                mins[i] = 2;
                node = i;
            }
            else {
                mins[i] = 1;
            }
        }

        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i) {
            if (parents[i] >= 0) {
                children[parents[i]].push_back(i);
            }
        }

        int pre = -1;
        unordered_set<int> owns;
        function<void(int)> dfs = [&](int i) {
            owns.insert(nums[i]);
            for (int j : children[i]) {
                if (j == pre) {
                    continue;
                }

                dfs(j);
            }
        };

        while (node >= 0) {
            if (pre >= 0) {
                mins[node] = mins[pre];
            }

            dfs(node);
            while (owns.count(mins[node])) {
                ++mins[node];
            }

            pre = node;
            node = parents[node];
        }

        return mins;
    }
};