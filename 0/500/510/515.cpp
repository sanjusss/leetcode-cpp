/*
 * @Author: sanjusss
 * @Date: 2022-06-24 08:39:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-24 08:45:33
 * @FilePath: \0\500\510\515.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            ans.emplace_back() = INT_MIN;
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                ans.back() = max(ans.back(), node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::largestValues)