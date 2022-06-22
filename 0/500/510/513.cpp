/*
 * @Author: sanjusss
 * @Date: 2022-06-22 08:30:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-22 08:33:01
 * @FilePath: \0\500\510\513.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            bool first = true;
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                if (first) {
                    first = false;
                    ans = node->val;
                }

                if (node->left != nullptr) {
                    q.emplace(node->left);
                }

                if (node->right != nullptr) {
                    q.emplace(node->right);
                }
            }
        }

        return ans;
    }
};