/*
 * @Author: sanjusss
 * @Date: 2021-11-26 14:09:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-26 14:27:19
 * @FilePath: \0\700\700\700.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->val == val) {
                return node;
            }

            if (val > node->val) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }

        return nullptr;
    }
};