#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    vector<int> preorderTraversal(TreeNode* root)
//    {
//        stack<TreeNode*> s;
//        s.push(root);
//        vector<int> res;
//        while (s.empty() == false)
//        {
//            auto node = s.top();
//            s.pop();
//            if (node == nullptr)
//            {
//                continue;
//            }
//
//            res.push_back(node->val);
//            s.push(node->right);
//            s.push(node->left);
//        }
//
//        return res;
//    }
//};

class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur != nullptr || s.empty() == false)
        {
            while (cur != nullptr)
            {
                res.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top()->right;
            s.pop();
        }

        return res;
    }
};