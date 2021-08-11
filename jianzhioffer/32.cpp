/*
 * @Author: sanjusss
 * @Date: 2021-08-11 10:49:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-11 10:52:05
 * @FilePath: \jianzhioffer\32.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ans.push_back(node->val);
            if (node->left != nullptr) {
                q.push(node->left);
            }

            if (node->right != nullptr) {
                q.push(node->right);
            }
        }

        return ans;
    }
};