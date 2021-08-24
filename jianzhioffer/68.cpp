/*
 * @Author: sanjusss
 * @Date: 2021-08-24 09:06:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-24 09:24:27
 * @FilePath: \jianzhioffer\68.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         auto path = [](stack<TreeNode*>& s, TreeNode* cur, TreeNode* target) {
//             while (cur->val != target->val) {
//                 s.push(cur);
//                 if (cur->val > target->val) {
//                     cur = cur->left;
//                 }
//                 else {
//                     cur = cur->right;
//                 }
//             }

//             s.push(cur);
//         };

//         stack<TreeNode*> ppath;
//         path(ppath, root, p);
//         stack<TreeNode*> qpath;
//         path(qpath, root, q);

//         while (ppath.size() > qpath.size()) {
//             ppath.pop();
//         }

//         while (qpath.size() > ppath.size()) {
//             qpath.pop();
//         }

//         while (qpath.top()->val != ppath.top()->val) {
//             qpath.pop();
//             ppath.pop();
//         }

//         return qpath.top();
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->val == p->val || node->val == q->val) {
                return node;
            }

            if ((node->val > p->val && node->val < q->val) || (node->val < p->val && node->val > q->val)) {
                return node;
            }

            if (node->val > p->val) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }

        return nullptr;
    }
};