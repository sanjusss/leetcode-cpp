#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<int> rightSideView(TreeNode* root) 
//    {
//        vector<int> ans;
//        rightSideView(root, 0, ans);
//        return ans;
//    }
//
//private:
//    void rightSideView(TreeNode* node, int level, vector<int>& view)
//    {
//        if (node == nullptr)
//        {
//            return;
//        }
//
//        if (view.size() == level)
//        {
//            view.push_back(node->val);
//        }
//
//        rightSideView(node->right, level + 1, view);
//        rightSideView(node->left, level + 1, view);
//    }
//};

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }

        vector<TreeNode*> q;
        q.push_back(root);
        while (q.empty() == false)
        {
            ans.push_back(q.back()->val);
            vector<TreeNode*> nexts;
            for (auto& node : q)
            {
                if (node->left != nullptr)
                {
                    nexts.push_back(node->left);
                }

                if (node->right != nullptr)
                {
                    nexts.push_back(node->right);
                }
            }

            q = move(nexts);
        }

        return ans;
    }
};