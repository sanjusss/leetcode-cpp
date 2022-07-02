/*
 * @Author: sanjusss
 * @Date: 2022-07-02 11:07:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-02 11:10:43
 * @FilePath: \0\300\310\314.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> pos;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto [node, p] = q.front();
            q.pop();
            if (node == nullptr) {
                continue;
            }

            pos[p].push_back(node->val);
            q.emplace(node->left, p - 1);
            q.emplace(node->right, p + 1);
        }

        vector<vector<int>> ans;
        for (auto &[_, arr] : pos) {
            ans.push_back(move(arr));
        }

        return ans;
    }
};