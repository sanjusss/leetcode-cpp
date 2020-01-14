#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<int> postorderTraversal(TreeNode* root) 
//    {
//        vector<int> res;
//        if (root != nullptr)
//        {
//            postorderTraversal(root, res);
//        }
//
//        return res;
//    }
//
//private:
//    void postorderTraversal(TreeNode* node, vector<int>& res)
//    {
//        if (node->left != nullptr)
//        {
//            postorderTraversal(node->left, res);
//        }
//
//        if (node->right != nullptr)
//        {
//            postorderTraversal(node->right, res);
//        }
//
//        res.push_back(node->val);
//    }
//};

////破坏性迭代
//class Solution 
//{
//public:
//    vector<int> postorderTraversal(TreeNode* root) 
//    {
//        vector<int> res;
//        if (root != nullptr)
//        {
//            stack<TreeNode*> s;
//            s.push(root);
//            while (s.empty() == false)
//            {
//                TreeNode* node = s.top();
//                if (node->left == nullptr && node->right == nullptr)
//                {
//                    res.push_back(node->val);
//                    s.pop();
//                }
//                else
//                {
//                    if (node->right != nullptr)
//                    {
//                        s.push(node->right);
//                        node->right = nullptr;
//                    }
//
//                    if (node->left != nullptr)
//                    {
//                        s.push(node->left);
//                        node->left = nullptr;
//                    }
//                }
//            }
//        }
//
//        return res;
//    }
//};

////非破坏性迭代
//class Solution
//{
//public:
//    vector<int> postorderTraversal(TreeNode* root)
//    {
//        vector<int> res;
//        if (root != nullptr)
//        {
//            stack<TreeNode*> s;
//            s.push(root);
//            unordered_set<TreeNode*> passed;
//            while (s.empty() == false)
//            {
//                TreeNode* node = s.top();
//                if (passed.find(node) != passed.end())
//                {
//                    res.push_back(node->val);
//                    s.pop();
//                }
//                else
//                {
//                    if (node->right != nullptr)
//                    {
//                        s.push(node->right);
//                    }
//
//                    if (node->left != nullptr)
//                    {
//                        s.push(node->left);
//                    }
//
//                    passed.insert(node);
//                }
//            }
//        }
//
//        return res;
//    }
//};

class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur != nullptr || s.empty() == false)
        {
            while (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            if (cur->right == nullptr || pre == cur->right)
            {
                s.pop();
                res.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            }
            else
            {
                cur = cur->right;
            }
        }

        return res;
    }
};