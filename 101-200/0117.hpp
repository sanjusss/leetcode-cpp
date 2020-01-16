#pragma once
#include "leetcode.h"

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//class Solution 
//{
//public:
//    Node* connect(Node* root) 
//    {
//        Node* cur = root;
//        Node* nextLevel = nullptr;
//        Node* pre = nullptr;
//        while (cur != nullptr)
//        {
//            do
//            {
//                if (cur->left != nullptr)
//                {
//                    if (pre != nullptr)
//                    {
//                        pre->next = cur->left;
//                    }
//
//                    pre = cur->left;
//                    if (nextLevel == nullptr)
//                    {
//                        nextLevel = cur->left;
//                    }
//                }
//
//                if (cur->right != nullptr)
//                {
//                    if (pre != nullptr)
//                    {
//                        pre->next = cur->right;
//                    }
//
//                    pre = cur->right;
//                    if (nextLevel == nullptr)
//                    {
//                        nextLevel = cur->right;
//                    }
//                }
//
//                cur = cur->next;
//            } while (cur != nullptr);
//
//            cur = nextLevel;
//            nextLevel = nullptr;
//            pre = nullptr;
//        }
//
//        return root;
//    }
//};

//¼ò»¯
class Solution
{
public:
    Node* connect(Node* root)
    {
        Node* cur = root;
        Node head;
        Node* pre = &head;
        while (cur != nullptr)
        {
            do
            {
                if (cur->left != nullptr)
                {
                    pre->next = cur->left;
                    pre = cur->left;
                }

                if (cur->right != nullptr)
                {
                    pre->next = cur->right;
                    pre = cur->right;
                }

                cur = cur->next;
            } while (cur != nullptr);

            cur = head.next;
            pre = &head;
            head.next = nullptr;
        }

        return root;
    }
};