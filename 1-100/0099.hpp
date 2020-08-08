#pragma once
#include "leetcode.h"

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (s.empty() == false || cur != nullptr) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();
            if (prev != nullptr && cur->val < prev->val) {
                second = cur;
                if (first == nullptr) {
                    first = prev;
                }
                else {
                    break;
                }
            }

            prev = cur;
            cur = cur->right;
        }

        swap(first->val, second->val);
    }
};