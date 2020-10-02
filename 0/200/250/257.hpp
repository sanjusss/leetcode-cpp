#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root != nullptr) {
            dfs(ans, root, string());
        }

        return ans;
    }

private:
    void dfs(vector<string>& ans, TreeNode* node, string cur) {
        if (!cur.empty()) {
            cur += "->";
        }

        cur += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(cur);
        }
        else {
            if (node->left != nullptr) {
                dfs(ans, node->left, cur);
            }

            if (node->right != nullptr) {
                dfs(ans, node->right, cur);
            }
        }
    }
};