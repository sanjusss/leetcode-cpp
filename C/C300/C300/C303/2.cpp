/*
 * @Author: sanjusss
 * @Date: 2022-07-24 10:28:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-24 10:41:45
 * @FilePath: \C\C300\C300\C303\2.cpp
 */
#include "leetcode.h"

struct Node {
    int cnt = 0;
    unordered_map<int, Node*> children;
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* root = new Node();
        for (int i = 0; i < n; ++i) {
            Node* node = root;
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                if (!(node->children.count(v))) {
                    node->children[v] = new Node();
                }

                node = node->children[v];
            }

            ++node->cnt;
        }

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            Node* node = root;
            bool success = true;
            for (int i = 0; i < n; ++i) {
                int v = grid[i][j];
                if (!(node->children.count(v))) {
                    success = false;
                    break;
                }

                node = node->children[v];
            }

            if (success) {
                ans += node->cnt;
            }
        }

        return ans;
    }
};