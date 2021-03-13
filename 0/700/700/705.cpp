/*
 * @Author: sanjusss
 * @Date: 2021-03-13 10:19:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-13 10:37:49
 * @FilePath: \0\700\700\705.cpp
 */
#include "leetcode.h"

// class MyHashSet {
// public:
//     /** Initialize your data structure here. */
//     MyHashSet() : m_set(1e6 + 1) {

//     }
    
//     void add(int key) {
//         m_set[key] = true;
//     }
    
//     void remove(int key) {
//         m_set[key] = false;
//     }
    
//     /** Returns true if this set contains the specified element */
//     bool contains(int key) {
//         return m_set[key];
//     }

// private:
//     vector<bool> m_set;
// };

class MyHashSet {
    struct Node {
        Node* next = nullptr;
        int val = 0;
    };

public:
    /** Initialize your data structure here. */
    MyHashSet() : m_set(m_mod) {

    }

    ~MyHashSet() {
        for (auto node : m_set) {
            while (node != nullptr) {
                auto next = node->next;
                delete node;
                node = next;
            }
        }
    }
    
    void add(int key) {
        Node*& head = m_set[key % m_mod];
        if (head == nullptr) {
            head = new Node();
            head->val = key;
            return;
        }

        Node* prev = nullptr;
        Node* node = head;
        do {
            if (node->val == key) {
                return;
            }
            else {
                prev = node;
                node = node->next;
            }
        } while (node != nullptr);

        prev->next = new Node();
        prev->next->val = key;
    }
    
    void remove(int key) {
        Node*& head = m_set[key % m_mod];
        if (head == nullptr) {
            return;
        }

        Node* prev = nullptr;
        Node* node = head;
        do {
            if (node->val == key) {
                if (prev == nullptr) {
                    head = node->next;
                }
                else {
                    prev->next = node->next;
                }
                
                delete node;
                return;
            }
            else {
                prev = node;
                node = node->next;
            }
        } while (node != nullptr);
    }
    
    bool contains(int key) {
        Node* node = m_set[key % m_mod];
        while (node != nullptr) {
            if (node->val == key) {
                return true;
            }
            else {
                node = node->next;
            }
        }

        return false;
    }

private:
    const int m_mod = 1009;
    vector<Node*> m_set;
};