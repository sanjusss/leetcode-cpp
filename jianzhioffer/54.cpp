/*
 * @Author: sanjusss
 * @Date: 2021-08-20 08:49:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-20 08:52:13
 * @FilePath: \jianzhioffer\54.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        TreeNode* node = root;
        stack<TreeNode*> s;
        while (!s.empty() || node != nullptr) {
            while (node != nullptr) {
                s.push(node);
                node = node->right;
            }

            node = s.top();
            s.pop();
            if (--k == 0) {
                return node->val;
            }
            else {
                node = node->left;
            }
        }

        return 0;
    }
};