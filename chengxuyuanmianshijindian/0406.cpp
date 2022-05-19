/*
 * @Author: sanjusss
 * @Date: 2022-05-16 09:07:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-16 09:12:06
 * @FilePath: \chengxuyuanmianshijindian\0406.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->val <= p->val) {
                node = node->right;
            }
            else {
                if (ans == nullptr || ans->val > node->val) {
                    ans = node;
                }
                
                node = node->left;
            }
        }

        return ans;
    }
};