#include "leetcode.h"

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<pair<TreeNode*, TreeNode*>> s;
        s.emplace(original, cloned);
        while (!s.empty()) {
            auto [o, c] = s.top();
            s.pop();
            if (o == nullptr) {
                continue;
            }

            if (o == target) {
                return c;
            }

            s.emplace(o->left, c->left);
            s.emplace(o->right, c->right);
        }

        return nullptr;
    }
};