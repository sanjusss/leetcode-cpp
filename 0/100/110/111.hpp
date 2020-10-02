#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int minDepth(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        else if (root->left == nullptr && root->right == nullptr) {
//            return 1;
//        }
//        else if (root->left == nullptr) {
//            return minDepth(root->right) + 1;
//        }
//        else if (root->right == nullptr) {
//            return minDepth(root->left) + 1;
//        }
//        else {
//            return min(minDepth(root->left), minDepth(root->right)) + 1;
//        }
//    }
//};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        do {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    return ans;
                }
                
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        } while (!q.empty());

        return ans;
    }
};