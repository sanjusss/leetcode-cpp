#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    TreeNode* invertTree(TreeNode* root) 
//    {
//        if (root != nullptr)
//        {
//            swap(root->left, root->right);
//            invertTree(root->left);
//            invertTree(root->right);
//        }
//
//        return root;
//    }
//};

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);
        do
        {
            auto node = q.front();
            q.pop();
            swap(node->left, node->right);
            if (node->left != nullptr)
            {
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        } while (!q.empty());

        return root;
    }
};