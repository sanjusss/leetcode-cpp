#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         else {
//             return 1 + countNodes(root->left) + countNodes(root->right);
//         }
//     }
// };

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int height = countHeight(root);
        int left = 1 << (height - 1);
        int right = (1 << height) - 1;
        int mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (existNode(root, height, mid)) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }

private:
    int countHeight(TreeNode* root) {
        int height = 0;
        while (root != nullptr) {
            root = root->left;
            ++height;
        }

        return height;
    }

    bool existNode(TreeNode* root, int height, int index) {
        for (int i = height - 2; i >= 0; --i) {
            if ((1 << i) & index) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        return root != nullptr;
    }
};