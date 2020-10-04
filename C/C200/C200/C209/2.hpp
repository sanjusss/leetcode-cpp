#pragma once

#include "leetcode.h"

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool isOdd = false;
        bool increase = false;
        int last;
        bool first;
        do {
            isOdd = !isOdd;
            increase = !increase;
            first = true; 
            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                if ((node->val % 2 == 1) != isOdd) {
                    return false;
                }

                if (first) {
                    first = false;
                }
                else {
                    if (increase) {
                        if (node->val <= last) {
                            return false;
                        }
                    }
                    else {
                        if (node->val >= last) {
                            return false;
                        }
                    }
                }

                last = node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        } while (!q.empty());

        return true;
    }
};