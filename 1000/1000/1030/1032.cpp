/*
 * @Author: sanjusss
 * @Date: 2023-03-24 08:32:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-24 09:25:04
 * @FilePath: \1000\1000\1030\1032.cpp
 */
#include "leetcode.h"

struct Node {
    Node* children[26] = {};
    bool end = false;
};
static Node sc_Nodes[1000000];

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        m_root = newNode();
        for (auto& w : words) {
            auto node = m_root;
            for (char c : w) {
                int i = c - 'a';
                if (node->children[i] == nullptr) {
                    node->children[i] = newNode(); 
                }

                node = node->children[i];
            }

            node->end = true;
        }
    }
    
    bool query(char letter) {
        bool res = false;
        int i = letter - 'a';
        m_q.push(m_root);
        for (int qi = m_q.size(); qi > 0; --qi) {
            auto node = m_q.front();
            m_q.pop();
            node = node->children[i];
            if (node == nullptr) {
                continue;
            }

            m_q.push(node);
            if (node->end) {
                res = true;
            }
        }

        return res;
    }

private:
    Node* newNode() {
        Node* node = &(sc_Nodes[m_index++]);
        memset(node, 0, sizeof(Node));
        return node;
    }

private:
    Node* m_root = nullptr;
    int m_index = 0;
    queue<Node*> m_q;
};