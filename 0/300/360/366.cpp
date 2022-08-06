/*
 * @Author: sanjusss
 * @Date: 2022-07-31 09:04:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-31 09:17:29
 * @FilePath: \0\300\360\366.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> findLeaves(TreeNode* root) {
//         vector<vector<int>> ans;
//         if (root == nullptr) {
//             return ans;
//         }

//         unordered_map<TreeNode*, TreeNode*> parents;
//         parents[root] = nullptr;
//         stack<TreeNode*> s;
//         s.push(root);
//         queue<TreeNode*> q;
//         while (!s.empty()) {
//             auto node = s.top();
//             s.pop();
//             if (node->right != nullptr) {
//                 parents[node->right] = node;
//                 s.push(node->right);
//             }
            
//             if (node->left != nullptr) {
//                 parents[node->left] = node;
//                 s.push(node->left);
//             }

//             if (node->left == nullptr && node->right == nullptr) {
//                 q.push(node);
//             }
//         }

//         while (!q.empty()) {
//             auto& row = ans.emplace_back();
//             for (int i = q.size(); i > 0; --i) {
//                 auto node = q.front();
//                 q.pop();
//                 row.push_back(node->val);
//                 auto parent = parents[node];
//                 if (parent == nullptr) {
//                     continue;
//                 }

//                 if (parent->left == node) {
//                     parent->left = nullptr;
//                 }
//                 else {
//                     parent->right = nullptr;
//                 }

//                 if (parent->left == nullptr && parent->right == nullptr) {
//                     q.push(parent);
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        function<int(TreeNode*)> dfs = [&] (TreeNode* node) -> int {
            if (node == nullptr) {
                return -1;
            }

            int depth = max(dfs(node->left), dfs(node->right)) + 1;
            if (depth == ans.size()) {
                ans.emplace_back();
            }

            ans[depth].push_back(node->val);
            return depth;
        };
        dfs(root);
        return ans;
    }
};