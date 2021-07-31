/*
 * @Author: sanjusss
 * @Date: 2021-07-31 10:00:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-31 10:12:23
 * @FilePath: \0\900\980\987.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        unordered_map<int, vector<int>> p2v;
        while (!q.empty()) {
            unordered_map<int, multiset<int>> row;
            for (int i = q.size(); i > 0; --i) {
                auto [node, p] = q.front();
                q.pop();
                row[p].insert(node->val);

                if (node->left != nullptr) {
                    q.emplace(node->left, p - 1);
                }

                if (node->right != nullptr) {
                    q.emplace(node->right, p + 1);
                }
            }

            for (auto& [p, vs] : row) {
                auto& vec = p2v[p];
                copy(vs.begin(), vs.end(), back_inserter(vec));
            }
        }

        set<int> keys;
        for (auto [p, _] : p2v) {
            keys.insert(p);
        }

        vector<vector<int>> ans;
        ans.reserve(keys.size());
        for (int p : keys) {
            ans.emplace_back(move(p2v[p]));
        }

        return ans;
    }
};

TEST(&Solution::verticalTraversal)