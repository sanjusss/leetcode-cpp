/*
 * @Author: sanjusss
 * @Date: 2022-03-21 09:20:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-21 09:25:26
 * @FilePath: \0\600\650\653.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                continue;
            }

            if (s.count(k - node->val)) {
                return true;
            }

            s.insert(node->val);
            q.push(node->left);
            q.push(node->right);
        }

        return false;
    }
};