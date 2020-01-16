#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int kthSmallest(TreeNode* root, int k) 
//    {
//        stack<TreeNode*> s;
//        TreeNode* cur = root;
//        while (cur != nullptr)
//        {
//            s.push(cur);
//            cur = cur->left;
//        }
//
//        while (s.empty() == false)
//        {
//            cur = s.top();
//            s.pop();
//            --k;
//            if (k == 0)
//            {
//                return cur->val;
//            }
//
//            if (cur->right != nullptr)
//            {
//                cur = cur->right;
//                do
//                {
//                    s.push(cur);
//                    cur = cur->left;
//                } while (cur != nullptr);
//            }
//        }
//
//        return INT_MIN;
//    }
//};

////������������������������Ǵ�С�������С��ݹ鷽��
//class Solution 
//{
//public:
//    int kthSmallest(TreeNode* root, int k) 
//    {
//        return find(root, k);
//    }
//
//private:
//    int find(TreeNode* node, int& k)
//    {
//        if (node == nullptr)
//        {
//            return INT_MIN;
//        }
//
//        int ans = find(node->left, k);
//        if (k == 0)
//        {
//            return ans;
//        }
//
//        --k;
//        if (k == 0)
//        {
//            return node->val;
//        }
//
//        return find(node->right, k);
//    }
//};

//������������������������Ǵ�С�������С�����������
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur != nullptr || s.empty() == false)
        {
            while (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top();
            s.pop();
            --k;
            if (k == 0)
            {
                return cur->val;
            }

            if (cur->right != nullptr)
            {
                cur = cur->right;
            }
            else
            {
                cur = nullptr;
            }
        }

        return INT_MIN;
    }
};