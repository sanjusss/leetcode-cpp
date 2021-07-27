/*
 * @Author: sanjusss
 * @Date: 2021-07-27 08:20:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-27 08:27:44
 * @FilePath: \0\600\670\671.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int ans = findBigger(root, root->val);
        return ans == root->val ? -1 : ans;
    }

private:
    int findBigger(TreeNode* node, int target) {
        if (node->left == nullptr) {
            return node->val;
        }

        int left = findBigger(node->left, target);
        int right = findBigger(node->right, target);
        if (min(left, right) == target) {
            return max(left, right);
        }
        else {
            return min(left, right);
        }
    }
};

TEST(&Solution::findSecondMinimumValue)