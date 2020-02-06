#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    //垃圾代码，强行动态规划。
//    int maxPathSum(TreeNode* root) 
//    {
//        stack<TreeNode*> s;
//        queue<TreeNode*> q;
//        q.push(root);
//        while (q.empty() == false)
//        {
//            TreeNode* node = q.front();
//            q.pop();
//
//            s.push(node);
//            if (node->left != nullptr)
//            {
//                q.push(node->left);
//            }
//
//            if (node->right != nullptr)
//            {
//                q.push(node->right);
//            }
//        }
//
//        unordered_map<TreeNode*, int> dp;
//        int maxSum = INT_MIN;
//        while (s.empty() == false)
//        {
//            TreeNode* node = s.top();
//            s.pop();
//
//            int res = node->val;
//            if (node->left != nullptr)
//            {
//                res = max(res, node->val + dp[node->left]);
//            }
//
//            if (node->right != nullptr)
//            {
//                res = max(res, node->val + dp[node->right]);
//            }
//
//            if (node->left != nullptr && node->right != nullptr)
//            {
//                maxSum = max(maxSum, node->val + dp[node->left] + dp[node->right]);
//            }
//
//            dp[node] = res;
//            maxSum = max(maxSum, res);
//        }
//
//        return maxSum;
//    }
//};

////递归列举所有情况
//class Solution
//{
//public:
//    int maxPathSum(TreeNode* root)
//    {
//        return find(root).first;
//    }
//
//private:
//    /*
//    返回值
//    first：最大值
//    second：包含node节点的最大路径，不能同时包含左右节点，可以只包括node节点。
//    */
//    pair<int, int> find(TreeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return { INT_MIN >> 2, INT_MIN >> 2};
//        }
//
//        auto lp = find(node->left);
//        auto rp = find(node->right);
//        int line = max({ node->val, node->val + lp.second, node->val + rp.second });
//        int value = max({ line, node->val + lp.second + rp.second, lp.first, rp.first });
//        return { value, line };
//    }
//};

//后续遍历，中途值参与最值比较。
class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        int ans = INT_MIN;
        //返回值：包含node节点的最大路径，不能同时包含左右节点，可以只包括node节点。
        auto find = [&ans](auto&& self, TreeNode* node)
        {
            if (node == nullptr)
            {
                return 0;
            }

            int left = max(0, self(self, node->left));
            int right = max(0, self(self, node->right));
            ans = max(ans, node->val + left + right);
            return max(node->val + left, node->val + right);
        };

        find(find, root);
        return ans;
    }
};