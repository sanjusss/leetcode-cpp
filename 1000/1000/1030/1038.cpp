#include "leetcode.h"

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root, 0);
        return root;
    }

private:
    int dfs(TreeNode* node, int sum) {
        if (node == nullptr) {
            return 0;
        }

        int right = dfs(node->right, sum);
        int val = node->val;
        node->val = sum + right + val;
        int left = dfs(node->left, node->val);
        return left + right + val;
    }
};