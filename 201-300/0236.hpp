#pragma once
#include "leetcode.h"

namespace _0236
{
    ////后序遍历
    //class Solution
    //{
    //public:
    //    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    //    {
    //        return find(root, p->val, q->val).first;
    //    }

    //private:
    //    pair<TreeNode*, int> find(TreeNode* node, int p, int q)
    //    {
    //        int count = 0;
    //        if (node->left != nullptr)
    //        {
    //            auto ans = find(node->left, p, q);
    //            if (ans.first != nullptr)
    //            {
    //                return ans;
    //            }
    //            else
    //            {
    //                count += ans.second;
    //            }
    //        }

    //        if (node->right != nullptr)
    //        {
    //            auto ans = find(node->right, p, q);
    //            if (ans.first != nullptr)
    //            {
    //                return ans;
    //            }
    //            else
    //            {
    //                count += ans.second;
    //            }
    //        }

    //        if (node->val == p || node->val == q)
    //        {
    //            ++count;
    //        }

    //        if (count == 2)
    //        {
    //            return { node, count };
    //        }
    //        else
    //        {
    //            return { nullptr, count };
    //        }
    //    }
    //};
        
    ////先序遍历
    //class Solution
    //{
    //public:
    //    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    //    {
    //        return find(root, p->val, q->val).first;
    //    }

    //private:
    //    pair<TreeNode*, int> find(TreeNode* node, int p, int q)
    //    {
    //        int count = 0;
    //        if (node->val == p || node->val == q)
    //        {
    //            ++count;
    //        }

    //        if (node->left != nullptr)
    //        {
    //            auto ans = find(node->left, p, q);
    //            if (ans.first != nullptr)
    //            {
    //                return ans;
    //            }
    //            else
    //            {
    //                count += ans.second;
    //            }
    //        }

    //        if (count == 2)
    //        {
    //            return { node, count };
    //        }

    //        if (node->right != nullptr)
    //        {
    //            auto ans = find(node->right, p, q);
    //            if (ans.first != nullptr)
    //            {
    //                return ans;
    //            }
    //            else
    //            {
    //                count += ans.second;
    //            }
    //        }

    //        if (count == 2)
    //        {
    //            return { node, count };
    //        }
    //        else
    //        {
    //            return { nullptr, count };
    //        }
    //    }
    //};

//递归
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        m_ans = nullptr;
        dfs(root, p, q);
        return m_ans;
    }

private:
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (node == nullptr)
        {
            return false;
        }

        bool left = dfs(node->left, p, q);
        bool right = dfs(node->right, p, q);
        if ((left && right) || ((node->val == p->val || node->val == q->val) && (left || right)))
        {
            m_ans = node;
        }

        return node->val == p->val || node->val == q->val || left || right;
    }

private:
    TreeNode* m_ans = nullptr;
};

}