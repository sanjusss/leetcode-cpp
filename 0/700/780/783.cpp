#include "leetcode.h"

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node = root;
        int prev = -1;
        int ans = INT_MAX;
        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            if (prev >= 0) {
                ans = min(ans, node->val - prev);
            }
            
            prev = node->val;
            node = node->right;
        }

        return ans;
    }
};

TEST(&Solution::minDiffInBST)