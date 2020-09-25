#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (root != nullptr) {
            vector<int> tmp;
            dfs(ans, root, sum, tmp);
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& ans, TreeNode* node, int target, vector<int>& cur) {
        cur.push_back(node->val);
        target -= node->val;
        if (target == 0 && node->left == nullptr && node->right == nullptr) {
            ans.push_back(cur);
        }
        else {
            if (node->left != nullptr) {
                dfs(ans, node->left, target, cur);
            }

            if (node->right != nullptr) {
                dfs(ans, node->right, target, cur);
            }
        }

        cur.pop_back();
    }
};