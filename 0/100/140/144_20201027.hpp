#include "leetcode.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        do {
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->right != nullptr) {
                s.push(node->right);
            }

            if (node->left != nullptr) {
                s.push(node->left);
            }
        } while (!s.empty());

        return ans;
    }
};