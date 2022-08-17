/*
 * @Author: sanjusss
 * @Date: 2022-08-17 08:09:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-17 08:11:30
 * @FilePath: \1000\1300\1300\1302.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans = 0;
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                ans += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};