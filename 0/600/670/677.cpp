/*
 * @Author: sanjusss
 * @Date: 2021-11-14 13:35:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-14 13:41:25
 * @FilePath: \0\600\670\677.cpp
 */
#include "leetcode.h"

class MapSum {
    struct Node {
        ~Node() {
            for (auto i : children) {
                delete i;
            }
        }

        Node* children[26]{};
        int sum = 0;
        int val = 0;
        bool end = false;
    };

public:
    MapSum() {
    }

    void insert(string key, int val) {
        Node* node = &m_root;
        stack<Node*> s;
        for (char c : key) {
            s.push(node);
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }

            node = node->children[i];
        }

        int diff = val - node->val;
        node->val = val;
        node->end = true;
        s.push(node);
        while (!s.empty()) {
            node = s.top();
            s.pop();
            node->sum += diff;
        }
    }

    int sum(string prefix) {
        Node* node = &m_root;
        for (char c : prefix) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return 0;
            }

            node = node->children[i];
        }

        return node->sum;
    }

private:
    Node m_root;
};