/*
 * @Author: sanjusss
 * @Date: 2024-02-20 11:21:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-20 12:08:12
 * @FilePath: \0\100\100\105_20240220.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int n = preorder.size();
        unordered_map<int, int> ipos;
        for (int i = 0; i < n; ++i) {
            ipos[inorder[i]] = i;
        }
        
        function<TreeNode*(int, int, int, int)> dfs = [&](int pb, int pe, int ib,
                                                          int ie) -> TreeNode* {
            if (pb >= pe) {
                return nullptr;
            }

            TreeNode* node = new TreeNode(preorder[pb]);
            int im = ipos[preorder[pb]];
            int left = im - ib;
            node->left = dfs(pb + 1, pb + 1 + left, ib, im);
            node->right = dfs(pb + 1 + left, pe, im + 1, ie);

            return node;
        };
        return dfs(0, n, 0, n);
    }
};