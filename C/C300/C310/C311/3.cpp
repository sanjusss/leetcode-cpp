/*
 * @Author: sanjusss
 * @Date: 2022-09-18 10:28:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-18 10:43:02
 * @FilePath: \C\C300\C310\C311\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*> row;
        row.emplace_back(root);
        for (int i = 0; !row.empty() && row.front() != nullptr; ++i) {
            int n = row.size();
            if (i % 2 == 1) {
                int left = 0;
                int right = n - 1;
                while (left < right) {
                    swap(row[left++]->val, row[right--]->val);
                }
            }

            for (int j = 0; j < n; ++j) {
                auto node = row.front();
                row.pop_front();
                row.push_back(node->left);
                row.push_back(node->right);
            }
        }

        return root;
    }
};