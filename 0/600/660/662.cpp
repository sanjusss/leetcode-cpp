/*
 * @Author: sanjusss
 * @Date: 2022-08-27 09:46:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-27 10:58:34
 * @FilePath: \0\600\660\662.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, uint64_t>> q;
        q.emplace_back(root, 0);
        uint64_t ans = 1;
        while (!q.empty()) {
            ans = max(ans, q.back().second - q.front().second + 1);
            for (int i = q.size(); i > 0; --i) {
                auto [node, j] = q.front();
                q.pop_front();
                if (node->left != nullptr) {
                    q.emplace_back(node->left, j * 2);
                }

                if (node->right != nullptr) {
                    q.emplace_back(node->right, j * 2 + 1);
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::widthOfBinaryTree)