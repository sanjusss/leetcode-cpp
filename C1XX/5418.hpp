#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int pseudoPalindromicPaths(TreeNode* root) 
    {
        return pseudoPalindromicPaths(root, 0);
    }

private:
    int pseudoPalindromicPaths(TreeNode* node, int status)
    {
        status ^= (1 << node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            int odds = 0;
            for (int i = 1; i <= 9; ++i)
            {
                if (status & (1 << i))
                {
                    ++odds;
                }
            }

            if (odds <= 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int ans = 0;
        if (node->left != nullptr)
        {
            ans += pseudoPalindromicPaths(node->left, status);
        }

        if (node->right != nullptr)
        {
            ans += pseudoPalindromicPaths(node->right, status);
        }

        return ans;
    }
};