/*
 * @Author: sanjusss
 * @Date: 2022-04-08 08:30:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-08 08:36:35
 * @FilePath: \0\400\420\429.cpp
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
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> row;
            for (int i = q.size(); i > 0; --i) {
                Node* node = q.front();
                q.pop();
                row.push_back(node->val);
                for (auto c : node->children) {
                    q.push(c);
                }
            }

            ans.push_back(move(row));
        }

        return ans;
    }
};