#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* current = root;
        while (current != nullptr || s.empty() == false)
        {
            while (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }

            auto node = s.top();
            s.pop();
            res.push_back(node->val);
            current = node->right;
        }
        
        return res;
    }

    //破坏树结构的迭代
    //vector<int> inorderTraversal(TreeNode* root)
    //{
    //    vector<int> res;
    //    stack<TreeNode*> s;
    //    s.push(root);

    //    do
    //    {
    //        auto node = s.top();
    //        s.pop();
    //        if (node == nullptr)
    //        {
    //            continue;
    //        }

    //        if (node->left == nullptr)
    //        {
    //            res.push_back(node->val);
    //            s.push(node->right);
    //        }
    //        else
    //        {
    //            s.push(node);
    //            s.push(node->left);
    //            node->left = nullptr;
    //        }
    //    } while (s.empty() == false);

    //    return res;
    //}

    //递归
//    vector<int> inorderTraversal(TreeNode* root) 
//    {
//        vector<int> res;
//        inorderTraversal(root, res);
//        return res;
//    }
//
//private:
//    void inorderTraversal(TreeNode* node, vector<int>& res)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//
//        inorderTraversal(node->left, res);
//        res.push_back(node->val);
//        inorderTraversal(node->right, res);
//    }
};