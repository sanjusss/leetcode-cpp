#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    TreeNode* convertBST(TreeNode* root) {
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        dfs(root, 0);
//        return root;
//    }
//
//private:
//    int dfs(TreeNode* node, int parent) {
//        int sum = node->val;
//        if (node->right == nullptr) {
//            node->val += parent;
//        }
//        else {
//            sum += dfs(node->right, parent);
//            node->val = sum + parent;
//        }
//
//        if (node->left != nullptr) {
//            sum += dfs(node->left, sum + parent);
//        }
//
//        return sum;
//    }
//};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        int sum = 0;
        dfs(root, sum);
        return root;
    }

private:
    void dfs(TreeNode* node, int& sum) {
        if (node->right != nullptr) {
            dfs(node->right, sum);
        }

        sum += node->val;
        node->val = sum;
        
        if (node->left != nullptr) {
            dfs(node->left, sum);
        }
    }
};