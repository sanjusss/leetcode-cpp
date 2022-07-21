/*
 * @Author: sanjusss
 * @Date: 2022-07-21 08:24:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-21 08:50:21
 * @FilePath: \0\200\270\272.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> closestKValues(TreeNode* root, double target, int k) {
//         vector<int> allge;
//         vector<int> allless;
//         function<void(TreeNode*)> dfsge = [&](TreeNode* node) {
//             if (node == nullptr || allge.size() >= k) {
//                 return;
//             }
//             else if (node->val < target) {
//                 dfsge(node->right);
//                 return;
//             }

//             dfsge(node->left);
//             if (allge.size() >= k) {
//                 return;
//             }

//             allge.push_back(node->val);
//             dfsge(node->right);
//         };
//         function<void(TreeNode*)> dfsless = [&](TreeNode* node) {
//             if (node == nullptr || allless.size() >= k) {
//                 return;
//             }
//             else if (node->val >= target) {
//                 dfsless(node->left);
//                 return;
//             }

//             dfsless(node->right);
//             if (allless.size() >= k) {
//                 return;
//             }

//             allless.push_back(node->val);
//             dfsless(node->left);
//         };
//         dfsge(root);
//         dfsless(root);
//         vector<int> ans;
//         int gei = 0;
//         int lessi = 0;
//         while (ans.size() < k && (gei < allge.size() || lessi < allless.size())) {
//             if (gei == allge.size()) {
//                 ans.push_back(allless[lessi++]);
//             }
//             else if (lessi == allless.size()) {
//                 ans.push_back(allge[gei++]);
//             }
//             else if (target - allless[lessi] <= allge[gei] - target) {
//                 ans.push_back(allless[lessi++]);
//             }
//             else {
//                 ans.push_back(allge[gei++]);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> q;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            if (q.size() == k) {
                if (fabs(target - q.front()) <= fabs(node->val - target)) {
                    break;
                }
                else {
                    q.pop_front();
                    q.push_back(node->val);
                }
            }
            else {
                q.push_back(node->val);
            }

            node = node->right;
        }

        return vector<int>(q.begin(), q.end());
    }
};

TEST_EQUIVALENT(&Solution::closestKValues)