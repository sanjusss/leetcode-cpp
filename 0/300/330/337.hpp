#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int rob(TreeNode* root) 
    {
        int maxValue;
        int notUse;
        rob(root, maxValue, notUse);
        return maxValue;
    }

private:
    void rob(TreeNode* node, int& maxValue, int& notUse)
    {
        maxValue = 0;
        notUse = 0;
        if (node == nullptr)
        {
            return;
        }

        int leftMax;
        int leftNotUse;
        rob(node->left, leftMax, leftNotUse);

        int rightMax;
        int rightNotUse;
        rob(node->right, rightMax, rightNotUse);

        notUse = leftMax + rightMax;
        maxValue = max(leftNotUse + rightNotUse + node->val, notUse);
    }
};

//class Solution
//{
//public:
//    int rob(TreeNode* root)
//    {
//        if (root == nullptr)
//        {
//            return 0;
//        }
//
//        vector<TreeNode*> trees;
//        trees.push_back(root);
//        int start = 0;
//        int end = 1;
//        while (start < end)
//        {
//            for (int i = start; i < end; ++i)
//            {
//                TreeNode* node = trees[i];
//                if (node->left != nullptr)
//                {
//                    trees.push_back(node->left);
//                }
//
//                if (node->right != nullptr)
//                {
//                    trees.push_back(node->right);
//                }
//            }
//
//            start = end;
//            end = trees.size();
//        }
//
//        unordered_map<TreeNode*, int> dp(trees.size() + 1);
//        dp[nullptr] = 0;
//
//        for (int i = trees.size() - 1; i >= 0; --i)
//        {
//            TreeNode* node = trees[i];
//            dp[node] = max(dp[node->left] + dp[node->right],
//                node->val +
//                (node->left == nullptr ? 0 : dp[node->left->left] + dp[node->left->right]) +
//                (node->right == nullptr ? 0 : dp[node->right->left] + dp[node->right->right]));
//        }
//
//        return dp[root];
//    }
//};