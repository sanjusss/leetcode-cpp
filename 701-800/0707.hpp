#pragma once
#include "leetcode.h"

class MyLinkedList 
{
    struct MyLinkedNode
    {
        int val;
        MyLinkedNode* next;
        MyLinkedNode(int x) : val(x), next(nullptr) {}
    };

public:
    /** Initialize your data structure here. */
    MyLinkedList() 
    {

    }

    ~MyLinkedList()
    {
        MyLinkedNode* temp;
        while (m_head != nullptr)
        {
            temp = m_head->next;
            delete m_head;
            m_head = temp;
        }
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        auto head = m_head;
        for (int i = 0; head != nullptr && i < index; ++i)
        {
            head = head->next;
        }

        return head == nullptr ? - 1 : head->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        auto tail = m_head;
        m_head = new MyLinkedNode(val);
        m_head->next = tail;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        auto node = new MyLinkedNode(val);
        if (m_head == nullptr)
        {
            m_head = node;
        }
        else
        {
            auto head = m_head;
            while (head->next != nullptr)
            {
                head = head->next;
            }

            head->next = node;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        MyLinkedNode* prev = nullptr;
        MyLinkedNode* head = m_head;
        for (int i = 0; i < index; ++i)
        {
            if (head == nullptr)
            {
                return;
            }

            prev = head;
            head = head->next;
        }

        MyLinkedNode* node = new MyLinkedNode(val);
        if (prev == nullptr)
        {
            node->next = m_head;
            m_head = node;
        }
        else
        {
            prev->next = node;
            node->next = head;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        MyLinkedNode* prev = nullptr;
        MyLinkedNode* head = m_head;
        for (int i = 0; i < index; ++i)
        {
            if (head == nullptr)
            {
                return;
            }

            prev = head;
            head = head->next;
        }

        if (prev == nullptr)
        {
            delete m_head;
            m_head = nullptr;
        }
        else if (head != nullptr)
        {
            prev->next = head->next;
            delete head;
        }
    }

private:
    MyLinkedNode* m_head = nullptr;
};