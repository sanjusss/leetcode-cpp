/*
 * @Author: sanjusss
 * @Date: 2022-03-06 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-06 11:01:05
 * @FilePath: \C\C200\C280\C283\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, bool> isRoot;
        unordered_map<int, int> lefts;
        unordered_map<int, int> rights;
        for (auto& d : descriptions) {
            isRoot[d[1]] = false;
            if (!isRoot.count(d[0])) {
                isRoot[d[0]] = true;
            }

            if (d[2]) {
                lefts[d[0]] = d[1];
            }
            else {
                rights[d[0]] = d[1];
            }
        }

        int root = -1;
        for (auto [i, is] : isRoot) {
            if (is) {
                root = i;
                break;
            }
        }

        function<TreeNode* (int)> dfs = [&](int i) -> TreeNode* {
            TreeNode* node = new TreeNode(i);
            if (lefts.count(i)) {
                node->left = dfs(lefts[i]);
            }

            if (rights.count(i)) {
                node->right = dfs(rights[i]);
            }

            return node;
        };

        return dfs(root);
    }
};