#pragma once
#include "leetcode.h"

class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTree(const vector<int>& preorder, int pStart, int pEnd, const vector<int>& inorder, int iStart, int iEnd)
    {
        if (pStart > pEnd)
        {
            return nullptr;
        }

        int mid = -1;
        int val = preorder[pStart];
        for (int i = iStart; i <= iEnd; ++i)
        {
            if (inorder[i] == val)
            {
                mid = i;
                break;
            }
        }

        if (mid == -1)
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(val);
        node->left = buildTree(preorder, pStart + 1, pStart + mid - iStart, inorder, iStart, mid - 1);
        node->right = buildTree(preorder, pStart + mid - iStart + 1, pEnd, inorder, mid + 1, iEnd);
        return node;
    }
};