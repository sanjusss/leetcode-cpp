/*
 * @Author: sanjusss
 * @Date: 2021-12-25 11:11:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-25 11:26:53
 * @FilePath: \1000\1600\1600\1609.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        bool isOdd = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int prev = isOdd ? INT_MAX : INT_MIN;
            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                if (node == nullptr) {
                    continue;
                }

                if (isOdd) {
                    if (node->val % 2 == 1 || node->val >= prev) {
                        return false;
                    }
                }
                else {
                    if (node->val % 2 == 0 || node->val <= prev) {
                        return false;
                    }
                }

                q.push(node->left);
                q.push(node->right);
                prev = node->val;
            }

            isOdd = !isOdd;
        }

        return true;
    }
};

TEST(&Solution::isEvenOddTree)