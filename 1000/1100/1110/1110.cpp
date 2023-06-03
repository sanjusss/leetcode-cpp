/*
 * @Author: sanjusss
 * @Date: 2023-05-30 08:25:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-30 08:31:12
 * @FilePath: \1000\1100\1110\1110.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> removes(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* node, bool hasParent) -> TreeNode* {
            if (node == nullptr) {
                return nullptr;
            }

            bool exist = !removes.count(node->val);
            if (!hasParent && exist) {
                ans.push_back(node);
            }

            node->left = dfs(node->left, exist);
            node->right = dfs(node->right, exist);
            return exist ? node : nullptr;
        };

        dfs(root, false);
        return ans;
    }
};