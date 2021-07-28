/*
 * @Author: sanjusss
 * @Date: 2021-07-28 09:16:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-28 09:28:05
 * @FilePath: \0\800\860\863.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != nullptr) {
                q.push(node->left);
                parents[node->left] = node;
            }

            if (node->right != nullptr) {
                q.push(node->right);
                parents[node->right] = node;
            }
        }

        unordered_set<TreeNode*> pass({ target });
        q.push(target);
        for (int i = 0; i < k && !q.empty(); ++i) {
            for (int j = q.size(); j > 0; --j) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr && pass.find(node->left) == pass.end()) {
                    pass.insert(node->left);
                    q.push(node->left);
                }

                if (node->right != nullptr && pass.find(node->right) == pass.end()) {
                    pass.insert(node->right);
                    q.push(node->right);
                }

                TreeNode* parent = parents[node];
                if (parent != nullptr && pass.find(parent) == pass.end()) {
                    pass.insert(parent);
                    q.push(parent);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};