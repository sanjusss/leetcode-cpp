#include "leetcode.h"

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node->val >= low && node->val <= high) {
                sum += node->val;
            }

            if (node->left && node->val > low) {
                s.push(node->left);
            }

            if (node->right && node->val < high) {
                s.push(node->right);
            }
        }

        return sum;
    }
};