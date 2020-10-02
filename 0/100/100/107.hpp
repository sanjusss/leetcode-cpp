#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        vector<vector<int>> ans;
//        queue<TreeNode*> q;
//        q.push(root);
//        do {
//            vector<int> cur;
//            for (int i = q.size(); i > 0; --i) {
//                TreeNode* node = q.front();
//                q.pop();
//                if (node == nullptr) {
//                    continue;
//                }
//
//                cur.push_back(node->val);
//                q.push(node->left);
//                q.push(node->right);
//            }
//
//            if (!cur.empty()) {
//                ans.push_back(cur);
//            }
//        } while (!q.empty());
//
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        do {
            vector<int> cur;
            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                cur.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (!cur.empty()) {
                ans.push_back(cur);
            }
        } while (!q.empty());

        reverse(ans.begin(), ans.end());
        return ans;
    }
};