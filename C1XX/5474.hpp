#pragma once
#include "leetcode.h"

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        if (root == nullptr) {
            return 0;
        }
        vector<int> ds(distance);
        return countPairs(root, distance, ds);
    }

private:
    int countPairs(TreeNode* node, int distance, vector<int>& ds) {
        if (node->left == nullptr && node->right == nullptr) {
            if (distance > 1) {
                ++ds[1];
            }
            return 0;
        }
        else if (node->left == nullptr) {
            int res = countPairs(node->right, distance, ds);
            for (int i = distance - 1; i > 0; --i) {
                ds[i] = ds[i - 1];
            }

            return res;
        }
        else if (node->right == nullptr) {
            int res = countPairs(node->left, distance, ds);
            for (int i = distance - 1; i > 0; --i) {
                ds[i] = ds[i - 1];
            }

            return res;
        }
        else {
            int res = 0;
            vector<int> dsLeft(distance);
            vector<int> dsRight(distance);
            res += countPairs(node->left, distance, dsLeft);
            res += countPairs(node->right, distance, dsRight);

            for (int i = distance - 1; i > 0; --i) {
                ds[i] = dsLeft[i - 1] + dsRight[i - 1];
            }

            for (int i = 1; i < distance; ++i) {
                dsRight[i] += dsRight[i - 1];
                res += dsLeft[distance - i] * dsRight[i];
            }

            return res;
        }
    }
};