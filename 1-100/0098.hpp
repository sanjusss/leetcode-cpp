#pragma once
#include "leetcode.h"

class Solution 
{
public:
    //中序遍历
    bool isValidBST(TreeNode* root) 
    {
        vector<int> arr;
        valueOfNodes(root, arr);
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i - 1] >= arr[i])
            {
                return false;
            }
        }

        return true;
    }

    void valueOfNodes(TreeNode* node, vector<int>& arr)
    {
        if (node == nullptr)
        {
            return;
        }

        valueOfNodes(node->left, arr);
        arr.push_back(node->val);
        valueOfNodes(node->right, arr);
    }

    //前序遍历
    //bool isValidBST(TreeNode* root)
    //{
    //    if (root == nullptr)
    //    {
    //        return true;
    //    }

    //    stack<tuple<TreeNode*, int, int>> s({ { root, INT_MIN, INT_MAX } });
    //    TreeNode* node;
    //    int minV;
    //    int maxV;
    //    do
    //    {
    //        auto i = s.top();
    //        s.pop();

    //        node = get<0>(i);
    //        minV = get<1>(i);
    //        maxV = get<2>(i);
    //        if (node->val < minV ||
    //            node->val > maxV)
    //        {
    //            return false;
    //        }

    //        if (node->left != nullptr)
    //        {
    //            if (node->val == INT_MIN)
    //            {
    //                return false;
    //            }

    //            s.push({ node->left, minV, node->val - 1 });
    //        }

    //        if (node->right != nullptr)
    //        {
    //            if (node->val == INT_MAX)
    //            {
    //                return false;
    //            }

    //            s.push({ node->right, node->val + 1, maxV });
    //        }
    //    } while (s.empty() == false);
    //    return true;
    //}
};