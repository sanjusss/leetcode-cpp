/*
 * @Author: sanjusss
 * @Date: 2022-06-02 08:21:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-02 09:03:03
 * @FilePath: \0\400\450\450.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode head(0);
        head.left = root;
        TreeNode** pnode = &(head.left);
        TreeNode* cur = head.left;
        while (cur != nullptr) {
            if (cur->val > key) {
                pnode = &(cur->left);
                cur = cur->left;
                continue;
            }
            else if (cur->val < key) {
                pnode = &(cur->right);
                cur = cur->right;
                continue;
            }

            if (cur->left == nullptr) {
                *pnode = cur->right;
            }
            else {
                TreeNode** ppos = &(cur->left);
                cur = cur->left;
                while (cur->right != nullptr) {
                    ppos = &(cur->right);
                    cur = cur->right;
                }

                *ppos = cur->left;
                cur->left = (*pnode)->left;
                cur->right = (*pnode)->right;
                *pnode = cur;
            }
            break;
        }

        return head.left;
    }
};

TEST(&Solution::deleteNode)