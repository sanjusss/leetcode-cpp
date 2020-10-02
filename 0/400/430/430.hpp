#pragma once
#include "leetcode.h"

class Node 
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) 
    {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        shared_ptr<Node> root(new Node());
        Node* current = root.get();
        stack<Node*> s({ head });
        do
        {
            auto node = s.top();
            s.pop();
            while (node != nullptr)
            {
                current->next = node;
                node->prev = current;
                current = node;
                if (node->child != nullptr)
                {
                    node = current->child;
                    current->child = nullptr;
                    s.push(current->next);
                }
                else
                {
                    node = current->next;
                }
            }

        } while (s.empty() == false);

        current->next = nullptr;
        if (root->next != nullptr)
        {
            root->next->prev = nullptr;
        }

        return root->next;
    }
};