/*
 * @Author: sanjusss
 * @Date: 2021-07-18 11:02:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-18 15:53:37
 * @FilePath: \C\C200\C250\C250\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
//         vector<int> ans;
//         ans.reserve(queries.size());
//         for (auto& q : queries) {
//             int node = q[0];
//             int val = q[1];
//             int res = 0;
//             do {
//                 res = max(res, (val ^ node));
//                 node = parents[node];
//             } while (node != -1);
//             ans.push_back(res);
//         }

//         return ans;
//     }
// };

class Solution {
    struct Trie {
        Trie* children[2] = { 0 };
        int cnt = 0;
    };
    struct Calc {
        static constexpr int K = 18;

        Calc(vector<int>& parents, vector<vector<int>>& queries)
            : ans(queries.size()), qs(parents.size()), children(parents.size()) {
            for (int i = 0; i < queries.size(); ++i) {
                qs[queries[i][0]].emplace_back(queries[i][1], i);
            }

            for (int i = 0; i < parents.size(); ++i) {
                if (parents[i] >= 0) {
                    children[parents[i]].push_back(i);
                }
                else {
                    root = i;
                }
            }
        }

        void calc() {
            dfs(root);
        }

        void dfs(int i) {
            push(i);
            for (auto& [val, j] : qs[i]) {
                ans[j] = search(val);
            }

            for (int j : children[i]) {
                dfs(j);
            }

            pop(i);
        } 

        void push(int i) {
            Trie* node = tree;
            for (int j = K - 1; j >= 0; --j) {
                int bit = (i & (1 << j)) ? 1 : 0;
                if (node->children[bit] == nullptr) {
                    node->children[bit] = new Trie();
                }

                node = node->children[bit];
                ++node->cnt;
            }
        }

        void pop(int i) {
            Trie* node = tree;
            for (int j = K - 1; j >= 0; --j) {
                int bit = (i & (1 << j)) ? 1 : 0;
                node = node->children[bit];
                --node->cnt;
            }
        }

        int search(int val) {
            Trie* node = tree;
            int res = 0;
            for (int j = K - 1; j >= 0; --j) {
                int bit = (val & (1 << j)) ? 1 : 0;
                int x = 1 - bit;
                if (node->children[x] == nullptr || node->children[x]->cnt == 0) {
                    node = node->children[1 - x];
                }
                else {
                    node = node->children[x];
                    res |= 1 << j;
                }
            }

            return res;
        }

        vector<int> ans;
        vector<vector<pair<int, int>>> qs;
        vector<vector<int>> children;
        int root = -1;
        Trie* tree = new Trie();
    };

public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        Calc calc(parents, queries);
        calc.calc();
        return move(calc.ans);
    }
};