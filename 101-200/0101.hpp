#pragma once
#include "leetcode.h"

class Solution 
{
public:
    //µü´ú
    bool isSymmetric(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return true;
        }

        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({ root->left, root->right });
        do
        {
            auto p = s.top();
            s.pop();
            auto left = p.first;
            auto right = p.second;

            if (left == nullptr)
            {
                if (right == nullptr)
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else if (right == nullptr)
            {
                return false;
            }
            else if (left->val != right->val)
            {
                return false;
            }
            else
            {
                s.push({ left->left, right->right });
                s.push({ left->right, right->left });
            }
        } while (s.empty() == false);

        return true;
    }

    ////µÝ¹é
    //bool isSymmetric(TreeNode* root)
    //{
    //    return root == nullptr || isSymmetric(root->left, root->right);
    //}

    //bool isSymmetric(TreeNode* left, TreeNode* right)
    //{
    //    if (left == nullptr)
    //    {
    //        return right == nullptr;
    //    }
    //    else if (right == nullptr || left->val != right->val)
    //    {
    //        return false;
    //    }
    //    else
    //    {
    //        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    //    }
    //}
};