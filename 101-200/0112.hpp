#pragma once
#include "leetcode.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }

        return hasPathSum(root, sum, 0);
    }

private:
    bool hasPathSum(TreeNode* node, int sum, int prev) {
        prev += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return sum == prev;
        }
        else {
            return (node->left != nullptr && hasPathSum(node->left, sum, prev)) ||
                (node->right != nullptr && hasPathSum(node->right, sum, prev));
        }
    }
};