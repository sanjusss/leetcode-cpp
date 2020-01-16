#pragma once
#include "leetcode.h"

class Node {
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
//        if (root != nullptr)
//        {
//            connecting(root);
//        }
//
//        return root;
//    }
//
//private:
//    void connecting(Node* node)
//    {
//        if (node->left == nullptr || node->right == nullptr)
//        {
//            return;
//        }
//
//        node->left->next = node->right;
//        if (node->next != nullptr)
//        {
//            node->right->next = node->next->left;
//        }
//
//        connecting(node->left);
//        connecting(node->right);
//    }
//};

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        Node* cur = root;
        Node* start = root;
        while (cur != nullptr)
        {
            if (cur->left != nullptr)
            {
                cur->left->next = cur->right;
                if (cur->next != nullptr)
                {
                    cur->right->next = cur->next->left;
                }
            }

            if (cur->next != nullptr)
            {
                cur = cur->next;
            }
            else
            {
                cur = start->left;
                start = cur;
            }
        }

        return root;
    }
};