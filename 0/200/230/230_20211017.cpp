/*
 * @Author: sanjusss
 * @Date: 2021-10-17 09:45:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-17 09:47:42
 * @FilePath: \0\200\230\230_20211017.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (!s.empty() || node != nullptr) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            if (--k == 0) {
                return node->val;
            }

            node = node->right;
        }

        return 0;
    }
};

TEST(&Solution::kthSmallest)