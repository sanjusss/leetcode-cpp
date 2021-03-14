/*
 * @Author: sanjusss
 * @Date: 2021-03-14 12:41:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-14 13:14:29
 * @FilePath: \0\700\700\706_20210314.cpp
 */

#include "leetcode.h"

// class MyHashMap {
//     struct Node {
//         int key = 0;
//         int val = 0;
//         Node* next = nullptr;
//     };

// public:
//     MyHashMap() : m_nodes(m_mod) {

//     }
    
//     ~MyHashMap() {
//         Node* temp;
//         for (auto& i : m_nodes) {
//             while (i != nullptr) {
//                 temp = i->next;
//                 delete i;
//                 i = temp;
//             }
//         }
//     }

//     void put(int key, int value) {
//         Node* node = m_nodes[key % m_mod];
//         if (node == nullptr) {
//             node = new Node();
//             node->key = key;
//             node->val = value;
//             m_nodes[key % m_mod] = node;
//             return;
//         }

//         if (node->key == key) {
//             node->val = value;
//             return;
//         }

//         while (node->next != nullptr) {
//             if (node->next->key == key) {
//                 node->next->val = value;
//                 return;
//             }
//             else {
//                 node = node->next;
//             }
//         }

//         node->next = new Node();
//         node = node->next;            
//         node->key = key;
//         node->val = value;
//     }
    
//     int get(int key) {
//         Node* node = m_nodes[key % m_mod];
//         while (node != nullptr) {
//             if (node->key == key) {
//                 return node->val;
//             }
//             else {
//                 node = node->next;
//             }
//         }

//         return -1;
//     }
    
//     void remove(int key) {
//         Node* node = m_nodes[key % m_mod];
//         if (node == nullptr) {
//             return;
//         }

//         if (node->key == key) {
//             m_nodes[key % m_mod] = nullptr;
//             delete node;
//             return;
//         }

//         while (node->next != nullptr) {
//             if (node->next->key == key) {
//                 auto temp = node->next;
//                 node->next = temp->next;
//                 delete temp;
//                 return;
//             }
//             else {
//                 node = node->next;
//             }
//         }
//     }

// private:
//     const int m_mod = 1007;
//     vector<Node*> m_nodes;
// };

class MyHashMap {
public:
    MyHashMap() : m_nodes(m_mod) {

    }

    void put(int key, int value) {
        auto& l = m_nodes[key % m_mod];
        for (auto& [k, v] : l) {
            if (k == key) {
                v = value;
                return;
            }
        }

        l.emplace_back(key, value);
    }
    
    int get(int key) {
        for (const auto& [k, v] : m_nodes[key % m_mod]) {
            if (k == key) {
                return v;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        auto& l = m_nodes[key % m_mod];
        for (auto i = l.begin(); i != l.end(); ++i) {
            if (i->first == key) {
                l.erase(i);
                return;
            }
        }
    }

private:
    const int m_mod = 1007;
    vector<list<pair<int, int>>> m_nodes;
};