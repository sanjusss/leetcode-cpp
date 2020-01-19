#pragma once
#include "leetcode.h"

//ºóÐò±éÀú
class Solution 
{
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if (root->left != nullptr)
        {
            root->left = removeLeafNodes(root->left, target);
        }

        if (root->right != nullptr)
        {
            root->right = removeLeafNodes(root->right, target);
        }

        if (root->left == nullptr && root->right == nullptr && root->val == target)
        {
            return nullptr;
        }
        else
        {
            return root;
        }
    }
};