#pragma once
#include "leetcode.h"

class Solution 
{
public:
    //垃圾代码，强行动态规划。
    int maxPathSum(TreeNode* root) 
    {
        stack<TreeNode*> s;
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() == false)
        {
            TreeNode* node = q.front();
            q.pop();

            s.push(node);
            if (node->left != nullptr)
            {
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }

        unordered_map<TreeNode*, int> dp;
        int maxSum = INT_MIN;
        while (s.empty() == false)
        {
            TreeNode* node = s.top();
            s.pop();

            int res = node->val;
            if (node->left != nullptr)
            {
                res = max(res, node->val + dp[node->left]);
            }

            if (node->right != nullptr)
            {
                res = max(res, node->val + dp[node->right]);
            }

            if (node->left != nullptr && node->right != nullptr)
            {
                maxSum = max(maxSum, node->val + dp[node->left] + dp[node->right]);
            }

            dp[node] = res;
            maxSum = max(maxSum, res);
        }

        return maxSum;
    }
};