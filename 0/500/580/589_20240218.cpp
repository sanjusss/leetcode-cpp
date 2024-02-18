/*
 * @Author: sanjusss
 * @Date: 2024-02-18 11:55:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-18 12:01:46
 * @FilePath: \0\500\580\589_20240218.cpp
 */
#include "leetcode.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> ans;
        deque<Node*> q;
        q.push_back(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop_front();
            ans.push_back(node->val);
            for (int i = int(node->children.size()) - 1; i >= 0; --i) {
                q.push_front(node->children[i]);
            }
        }

        return ans;
    }
};