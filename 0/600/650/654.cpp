/*
 * @Author: sanjusss
 * @Date: 2022-08-20 16:35:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-20 17:37:01
 * @FilePath: \0\600\650\654.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         list<TreeNode*> nodes;
//         map<int, decltype(nodes)::iterator> orders;
//         for (int i : nums) {
//             TreeNode* node = new TreeNode(i);
//             orders[i] = nodes.insert(nodes.end(), node);
//         }

//         for (auto [i, iter] : orders) {
//             if (nodes.size() == 1) {
//                 break;
//             }

//             if (iter == nodes.begin()) {
//                 (*next(iter))->left = *iter;
//             }
//             else if (next(iter) == nodes.end()) {
//                 (*prev(iter))->right = *iter;
//             }
//             else {
//                 auto pre  = *prev(iter);
//                 auto nxt = *next(iter);
//                 if (pre->val < nxt->val) {
//                     pre->right = *iter;
//                 }
//                 else {
//                     nxt->left = *iter;
//                 }
//             }

//             nodes.erase(iter);
//         }

//         return nodes.front();
//     }
// };

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s;
        for (int i : nums) {
            TreeNode* node = new TreeNode(i);
            while (!s.empty() && s.back()->val < node->val) {
                node->left = s.back();
                s.pop_back();
            }

            if (!s.empty()) {
                s.back()->right = node;
            }

            s.push_back(node);
        }

        return s.front();
    }
};