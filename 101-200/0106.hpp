#pragma once
#include "leetcode.h"

namespace Code0106
{

    class Solution
    {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
        {
            return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        }

    private:
        TreeNode* buildTree(const vector<int>& inorder, int iStart, int iEnd, const vector<int>& postorder, int pStart, int pEnd)
        {
            if (pStart > pEnd)
            {
                return nullptr;
            }

            int val = postorder[pEnd];
            int mid = -1;
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
            node->left = buildTree(inorder, iStart, mid - 1, postorder, pStart, pStart + mid - iStart - 1);
            node->right = buildTree(inorder, mid + 1, iEnd, postorder, pStart + mid - iStart, pEnd - 1);
            return node;
        }
    };

}