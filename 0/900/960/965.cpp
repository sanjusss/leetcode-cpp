/*
 * @Author: sanjusss
 * @Date: 2022-05-24 08:16:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-24 08:20:02
 * @FilePath: \0\900\960\965.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                continue;
            }
            else if (node->val != val) {
                return false;
            }
            else {
                q.emplace(node->left);
                q.emplace(node->right);
            }
        }

        return true;
    }
};