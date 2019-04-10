#pragma once
#include "leetcode.h"

class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
        map<int, Node*> nodes;
        stack<Node*> s;

        Node* root = new Node();
        root->val = node->val;
        nodes.insert({ root->val, root });
        s.push(node);

        do
        {
            auto src = s.top();
            s.pop();
            auto des = nodes[src->val];
            for (auto i : src->neighbors)
            {
                Node* n;
                if (nodes.find(i->val) != nodes.end())
                {
                    n = nodes[i->val];
                }
                else
                {
                    n = new Node();
                    n->val = i->val;
                    nodes[n->val] = n;
                    s.push(i);
                }

                des->neighbors.push_back(n);
            }

        } while (s.empty() == false);

        return root;
    }
};