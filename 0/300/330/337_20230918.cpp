#include "leetcode.h"

class Solution {
public:
    int rob(TreeNode* root) {
        return dfs(root).first;
    }

private:
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return { 0, 0 };
        }

        auto [cl, nl] = dfs(node->left);
        auto [cr, nr] = dfs(node->right);
        return { max(cl + cr, node->val + nl + nr), cl + cr };
    }
};