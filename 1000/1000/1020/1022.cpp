/*
 * @Author: sanjusss
 * @Date: 2022-05-30 09:07:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-30 09:11:11
 * @FilePath: \1000\1000\1020\1022.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left == nullptr && node->right == nullptr) {
                ans += node->val;
            }
            else {
                if (node->left != nullptr) {
                    node->left->val += node->val << 1;
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    node->right->val += node->val << 1;
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};