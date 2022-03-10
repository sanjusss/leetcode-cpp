/*
 * @Author: sanjusss
 * @Date: 2022-03-10 08:42:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-10 08:47:48
 * @FilePath: \0\500\580\589.cpp
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
        vector<int> ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            if (node == nullptr) {
                continue;
            }

            ans.push_back(node->val);
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i) {
                s.push(*i);
            }
        } 

        return ans;
    }
};