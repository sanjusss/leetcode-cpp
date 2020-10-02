#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return {};
        }
        else {
            return generateTrees(1, n);
        }
    }

private:
    void copyTree(TreeNode* src, TreeNode*& des) {
        if (src == nullptr) {
            return;
        }

        des = new TreeNode(src->val);
        copyTree(src->left, des->left);
        copyTree(src->right, des->right);
    }

    vector<TreeNode*> generateTrees(int left, int right) {
        if (m_cache.find(left * 100 + right) != m_cache.end()) {
            return m_cache[left * 100 + right];
        }

        vector<TreeNode*> ans;
        for (int i = left; i <= right; ++i) {
            TreeNode node(i);
            auto leftTrees = generateTrees(left, i - 1);
            auto rightTrees = generateTrees(i + 1, right);
            for (auto leftNode : leftTrees) {
                for (auto rightNode : rightTrees) {
                    node.left = leftNode;
                    node.right = rightNode;
                    TreeNode* temp = nullptr;
                    copyTree(&node, temp);
                    ans.push_back(temp);
                }
            }
        }

        if (ans.empty()) {
            ans.push_back(nullptr);
        }

        m_cache[left * 100 + right] = ans;
        return ans;
    }

private:
    unordered_map<int, vector<TreeNode*>> m_cache;
};