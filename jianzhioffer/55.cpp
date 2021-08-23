/*
 * @Author: sanjusss
 * @Date: 2021-08-23 08:34:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-23 08:37:04
 * @FilePath: \jianzhioffer\55.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node);
                }

                if (node->right != nullptr) {
                    q.push(node);
                }
            }
        }

        return ans;
    }
};