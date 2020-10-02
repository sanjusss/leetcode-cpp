#pragma once
#include "leetcode.h"

//namespace _0235 {
//    class Solution {
//    public:
//        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//            if (root == nullptr) {
//                return root;
//            }
//
//            if (root == p || root == q) {
//                return root;
//            }
//
//            TreeNode* lr = lowestCommonAncestor(root->left, p, q);
//            TreeNode* rr = lowestCommonAncestor(root->right, p, q);
//            if (lr != nullptr && rr != nullptr) {
//                return root;
//            }
//            else if (lr != nullptr) {
//                return lr;
//            }
//            else if (rr != nullptr) {
//                return rr;
//            }
//            else {
//                return nullptr;
//            }
//        }
//    };
//}

namespace _0235
{

    class Solution
    {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            if (root->val == p->val || root->val == q->val)
            {
                return root;
            }

            if (root->val > p->val)
            {
                if (root->val > q->val)
                {
                    return lowestCommonAncestor(root->left, p, q);
                }
                else
                {
                    return root;
                }
            }
            else
            {
                if (root->val > q->val)
                {
                    return root;
                }
                else
                {
                    return lowestCommonAncestor(root->right, p, q);
                }
            }
        }
    };

}