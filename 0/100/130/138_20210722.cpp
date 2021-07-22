/*
 * @Author: sanjusss
 * @Date: 2021-07-22 08:17:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-22 08:56:03
 * @FilePath: \0\100\130\138_20210722.cpp
 */
#include "leetcode.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> news;
//         news[nullptr] = nullptr;
//         Node root(0);
//         Node* cur = &root;
//         Node* node = head;
//         while (node != nullptr) {
//             cur->next = new Node(node->val);
//             news[node] = cur->next;
//             cur = cur->next;
//             node = node->next;
//         }

//         node = head;
//         cur = root.next;
//         while (node != nullptr) {
//             cur->random = news[node->random];
//             cur = cur->next;
//             node = node->next;
//         }

//         return root.next;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node = head;
        while (node != nullptr) {
            Node* next = node->next;
            node->next = new Node(node->val);
            node->next->next = next;
            node = next;
        }

        node = head;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }

            node = node->next->next;
        }

        Node ansRoot(0);
        Node* newList = &ansRoot;
        node = head;
        while (node != nullptr) {
            Node* next = node->next->next;
            newList->next = node->next;
            newList = newList->next;
            node->next = next;
            node = next;
        }

        return ansRoot.next;
    }
};