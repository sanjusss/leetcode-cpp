#pragma once
#include "leetcode.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        }

        TreeNode* node = new TreeNode((t1 == nullptr ? 0 : t1->val) + (t2 == nullptr ? 0 : t2->val));
        node->left = mergeTrees(t1 == nullptr ? 0 : t1->left, t2 == nullptr ? nullptr : t2->left);
        node->right = mergeTrees(t1 == nullptr ? 0 : t1->right, t2 == nullptr ? nullptr : t2->right);
        return node;
    }
};