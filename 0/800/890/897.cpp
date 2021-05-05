#include "leetcode.h"

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = nullptr;
        TreeNode* prev = nullptr;
        TreeNode* node = root;
        stack<TreeNode*> s;
        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            if (prev == nullptr) {
                ans = node;
            }
            else {
                prev->right = node;
            }

            prev = node;
            node->left = nullptr;
            node = node->right;
        }

        return ans;
    }
};

TEST(&Solution::increasingBST)