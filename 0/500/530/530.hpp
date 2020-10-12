/*
 * @Author: sanjusss
 * @Date: 2020-10-12 10:19:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-12 10:26:23
 * @FilePath: \0\500\530\530.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        stack<TreeNode*> s;
        TreeNode* node = root;
        int ans = INT_MAX;
        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            if (prev >= 0) {
                ans = min(ans, node->val - prev);
            }

            prev = node->val;
            node = node->right;
        }

        return ans;
    }
};