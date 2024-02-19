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
        if (!root) {
            return {};
        }

        vector<int> ans;
        deque<Node*> q;
        q.push_back(root);
        while (!q.empty()) {
            auto node = q.front();
            if (node->children.empty()) {
                q.pop_front();
                ans.push_back(node->val);
            }
            else {
                do {
                    q.push_front(node->children.back());
                    node->children.pop_back();
                } while (node->children.empty() == false);
            }
        }

        return ans;
    }
};