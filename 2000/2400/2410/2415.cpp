/*
 * @Author: sanjusss
 * @Date: 2023-12-15 10:43:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-15 11:39:59
 * @FilePath: \2000\2400\2410\2415.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {;
        vector<TreeNode*> cur;
        cur.push_back(root);
        for (int flip = 0; cur.front() != nullptr; flip = 1 - flip) {
            if (flip) {
                int left = 0;
                int right = (int)cur.size() - 1;
                while (left < right) {
                    swap(cur[left++]->val, cur[right--]->val);
                }
            }

            vector<TreeNode*> nxt;
            for (TreeNode* node : cur) {
                nxt.push_back(node->left);
                nxt.push_back(node->right);
            }

            cur = move(nxt);
        }

        return root;
    }
};