#pragma once
#include "leetcode.h"

class Solution {
    struct Status {
        int onThis = INT_MAX >> 1;
        int coverAll = 0;
        int coverChildren = 0;
    };

public:
    int minCameraCover(TreeNode* root) {
        Status s = dfs(root);
        return s.coverAll;
    }

private:
    Status dfs(TreeNode* node) {
        Status ans;
        if (node == nullptr) {
            return ans;
        }

        Status ls = dfs(node->left);
        Status rs = dfs(node->right);
        ans.onThis = ls.coverChildren + rs.coverChildren + 1;
        ans.coverChildren = min(ans.onThis, ls.coverAll + rs.coverAll);
        ans.coverAll = min({ ans.onThis, ls.coverAll + rs.onThis, ls.onThis + rs.coverAll });
        return ans;
    }
};