#include "leetcode.h"

class Solution {
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&dfs, &ans](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }

            int left = dfs(node->left);
            int right = dfs(node->right);
            ans += abs(left - right);
            return left + right + node->val;
        };

        dfs(root);
        return ans;
    }
};