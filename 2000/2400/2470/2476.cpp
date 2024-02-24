/*
 * @Author: sanjusss
 * @Date: 2024-02-24 11:29:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-24 11:34:25
 * @FilePath: \2000\2400\2470\2476.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        set<int> s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (!node) {
                continue;
            }

            s.insert(node->val);
            q.push(node->left);
            q.push(node->right);
        }

        vector<vector<int>> ans;
        for (auto& q : queries) {
            auto& a = ans.emplace_back(2, -1);
            auto p = s.lower_bound(q);
            if (p != s.end()) {
                a[1] = *p;
                if (*p == q) {
                    a[0] = q;
                    continue;
                }
            }

            if (p != s.begin()) {
                a[0] = *prev(p);
            }
        }

        return ans;
    }
};