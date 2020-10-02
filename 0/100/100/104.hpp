#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int maxDepth(TreeNode* root) 
//    {
//        if (root == nullptr)
//        {
//            return 0;
//        }
//        else
//        {
//            return 1 + max(maxDepth(root->left), maxDepth(root->right));
//        }
//    }
//};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        do {
            ++ans;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        } while (!q.empty());

        return ans;
    }
};