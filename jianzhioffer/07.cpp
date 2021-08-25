/*
 * @Author: sanjusss
 * @Date: 2021-08-25 09:23:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-25 10:16:58
 * @FilePath: \jianzhioffer\07.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         function<TreeNode*(int, int, int, int)> dfs = [&] (int pl, int pr, int il, int lr) -> TreeNode* {
//             if (pl > pr || il > lr) {
//                 return nullptr;
//             }

//             TreeNode* node = new TreeNode(preorder[pl]);
//             int imid = il;
//             while (imid <= lr) {
//                 if (inorder[imid] != preorder[pl]) {
//                     ++imid;
//                 }
//                 else {
//                     break;
//                 }
//             }

//             node->left = dfs(pl + 1, pl + imid - il, il, imid - 1);
//             node->right = dfs(pl + imid - il + 1, pr, imid + 1, lr);
//             return node;
//         };

//         return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
//     }
// };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);
        int j = 0;
        for (int i = 1; i < n; ++i) {
            TreeNode* node = s.top();
            if (node->val == inorder[j]) {
                while (!s.empty() && s.top()->val == inorder[j]) {
                    node = s.top();
                    s.pop();
                    ++j;
                }

                node->right = new TreeNode(preorder[i]);
                s.push(node->right);
            }
            else {
                node->left = new TreeNode(preorder[i]);
                s.push(node->left);
            }
        }

        return root;
    }
};