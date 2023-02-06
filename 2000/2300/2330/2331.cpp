/*
 * @Author: sanjusss
 * @Date: 2023-02-06 08:50:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-06 08:52:48
 * @FilePath: \2000\2300\2330\2331.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->val < 2) {
            return root->val == 1;
        }
        else if (root->val == 3) {
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
        else {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }
    }
};