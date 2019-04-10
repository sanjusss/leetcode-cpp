#pragma once
#include <vector>

// Definition for a Node.
class Node {
public:
    int val = 0;
    std::vector<Node*> neighbors;

    Node() {}

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};