#pragma once
#include "leetcode.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//class Solution 
//{
//public:
//    Node* cloneGraph(Node* node) 
//    {
//        map<int, Node*> nodes;
//        stack<Node*> s;
//
//        Node* root = new Node();
//        root->val = node->val;
//        nodes.insert({ root->val, root });
//        s.push(node);
//
//        do
//        {
//            auto src = s.top();
//            s.pop();
//            auto des = nodes[src->val];
//            for (auto i : src->neighbors)
//            {
//                Node* n;
//                if (nodes.find(i->val) != nodes.end())
//                {
//                    n = nodes[i->val];
//                }
//                else
//                {
//                    n = new Node();
//                    n->val = i->val;
//                    nodes[n->val] = n;
//                    s.push(i);
//                }
//
//                des->neighbors.push_back(n);
//            }
//
//        } while (s.empty() == false);
//
//        return root;
//    }
//};

//class Solution {
//public:
//    Node* cloneGraph(Node* node) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//
//        unordered_map<Node*, Node*> copied;
//        return cloneGraph(node, copied);
//    }
//
//private:
//    Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& copied) {
//        if (copied.find(node) != copied.end()) {
//            return copied[node];
//        }
//
//        Node* res = new Node(node->val);
//        copied[node] = res;
//        for (auto i : node->neighbors) {
//            res->neighbors.push_back(cloneGraph(i, copied));
//        }
//
//        return res;
//    }
//};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> copied;
        queue<Node*> q;
        Node* root = new Node(node->val);
        q.push(node);
        copied[node] = root;
        do {
            Node* src = q.front();
            q.pop();
            Node* des = copied[src];
            for (auto i : src->neighbors) {
                if (copied.find(i) == copied.end()) {
                    copied[i] = new Node(i->val);
                    q.push(i);
                }

                des->neighbors.push_back(copied[i]);
            }
        } while (!q.empty());

        return root;
    }
};