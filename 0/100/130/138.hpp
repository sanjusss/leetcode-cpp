#pragma once
#include "leetcode.h"

class Node 
{
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) 
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution 
{
public:
    //将拷贝节点作为源节点的下一节点，最后还原源链表。
    Node* copyRandomList(Node* head) 
    {
        Node* p = head;
        while (p != nullptr)
        {
            p->next = new Node(p->val, p->next, p->random);//将拷贝节点作为源节点的下一节点
            p = p->next->next;
        }

        p = head;
        while (p != nullptr)
        {
            if (p->next->random != nullptr)
            {
                p->next->random = p->next->random->next;//通过next指针获取下一节点
            }

            p = p->next->next;
        }

        p = head;
        shared_ptr<Node> root(new Node(0, nullptr, nullptr));
        Node* q = root.get();
        while (p != nullptr)
        {
            q->next = p->next;
            q = q->next;
            p->next = p->next->next;//还原源节点
            p = p->next;
        }

        return root->next;
    }

    //使用map存储节点，不破坏原表。
    //Node* copyRandomList(Node* head)
    //{
    //    map<Node*, Node*> funs;
    //    shared_ptr<Node> root(new Node(0, nullptr, nullptr));
    //    Node* des = root.get();
    //    Node* temp = nullptr;
    //    while (head != nullptr)
    //    {
    //        temp = new Node(head->val, nullptr, head->random);
    //        funs[head] = temp;
    //        des->next = temp;
    //        des = temp;
    //        head = head->next;
    //    }

    //    des = root->next;
    //    while (des != nullptr)
    //    {
    //        if (des->random != nullptr)
    //        {
    //            des->random = funs[des->random];
    //        }

    //        des = des->next;
    //    }

    //    return root->next;
    //}
};