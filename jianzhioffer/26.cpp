/*
 * @Author: sanjusss
 * @Date: 2021-08-12 09:45:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-12 10:05:41
 * @FilePath: \jianzhioffer\26.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr) {
            return false;
        }

        stack<TreeNode*> s;
        s.push(A);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node == nullptr) {
                continue;
            }

            stack<pair<TreeNode*, TreeNode*>> sp;
            sp.emplace(node, B);
            bool success = true;
            while (!sp.empty()) {
                auto [a, b] = sp.top();
                sp.pop();
                if (b == nullptr) {
                    continue;
                }

                if (a == nullptr || a->val != b->val) {
                    success = false;
                    break;
                }

                sp.emplace(a->left, b->left);
                sp.emplace(a->right, b->right);
            }

            if (success) {
                return true;
            }
            
            s.push(node->left);
            s.push(node->right);
        }

        return false;
    }
};

TEST(&Solution::isSubStructure)