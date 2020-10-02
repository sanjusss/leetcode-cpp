#pragma once
#include "leetcode.h"

class Solution 
{
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
    {
        return constructFromPrePost(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }

private:
    TreeNode* constructFromPrePost(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd)
    {
        if (preStart > preEnd)
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(pre[preStart]);
        if (preStart + 1 <= preEnd)
        {
            int val = pre[preStart + 1];
            int mid = -1;
            for (int i = postStart; i <= postEnd; ++i)
            {
                if (post[i] == val)
                {
                    mid = i;
                    break;
                }
            }

            if (mid == -1)
            {
                return node;
            }

            node->left = constructFromPrePost(pre, preStart + 1, preStart + mid - postStart + 1, post, postStart, mid);
            node->right = constructFromPrePost(pre, preStart + mid - postStart + 2, preEnd, post, mid + 1, postEnd - 1);
        }

        return node;
    }
};