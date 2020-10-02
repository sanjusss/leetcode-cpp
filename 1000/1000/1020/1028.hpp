#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    TreeNode* recoverFromPreorder(string S) 
//    {
//        if (S.empty())
//        {
//            return nullptr;
//        }
//
//        vector<vector<TreeNode*>> tree;
//        int height = 0;
//        int size = S.size();
//        for (int i = 0; i < size; ++i)
//        {
//            if (S[i] == '-')
//            {
//                ++height;
//                continue;
//            }
//
//            int j = i;
//            int value = 0;
//            while (j < size && isdigit(S[j]))
//            {
//                value = value * 10 + S[j] - '0';
//                ++j;
//            }
//
//            TreeNode* node = new TreeNode(value);
//            if (tree.size() <= height)
//            {
//                tree.push_back(vector<TreeNode*>());
//            }
//
//            tree[height].push_back(node);
//            if (height > 0)
//            {
//                TreeNode* parent = tree[height - 1].back();
//                if (parent->left == nullptr)
//                {
//                    parent->left = node;
//                }
//                else
//                {
//                    parent->right = node;
//                }
//            }
//
//            height = 0;
//            i = j - 1;
//        }
//
//        return tree[0][0];
//    }
//};

class Solution
{
public:
    TreeNode* recoverFromPreorder(string S)
    {
        TreeNode* root = nullptr;
        int prevHeight = 0;
        int height = 0;
        int size = S.size();
        stack<TreeNode*> tree;
        for (int i = 0; i < size; ++i)
        {
            if (S[i] == '-')
            {
                ++height;
                continue;
            }

            int j = i;
            int v = 0;
            while (j < size && isdigit(S[j]))
            {
                v = v * 10 + S[j] - '0';
                ++j;
            }

            TreeNode* node = new TreeNode(v);
            if (root == nullptr)
            {
                root = node;
            }
            else
            {
                for (int k = height; k <= prevHeight; ++k)
                {
                    tree.pop();
                }

                if (tree.top()->left == nullptr)
                {
                    tree.top()->left = node;
                }
                else
                {
                    tree.top()->right = node;
                }
            }

            tree.push(node);
            prevHeight = height;
            height = 0;
            i = j - 1;
        }

        return root;
    }
};