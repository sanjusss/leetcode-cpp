/*
 * @Author: sanjusss
 * @Date: 2022-03-12 09:14:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-12 09:25:28
 * @FilePath: \0\500\590\590.cpp
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
    vector<int> postorder(Node* root) {
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
            for (auto i : node->children) {
                s.push(i);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};