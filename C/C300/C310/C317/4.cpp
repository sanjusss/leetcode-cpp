/*
 * @Author: sanjusss
 * @Date: 2022-10-30 11:01:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-30 11:31:29
 * @FilePath: \C\C300\C310\C317\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        m_h = calcHeight(root);
        calcRemove(root, 0, true);
        vector<int> ans;
        for (int i : queries) {
            ans.push_back(m_ifremove[i] - 1);
        }

        return ans;
    }

private:
    int calcHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            return m_heights[node->val] = 1 + max(calcHeight(node->left), calcHeight(node->right));
        }
    }

    void calcRemove(TreeNode* node, int h2, bool inH) {
        if (!inH) {
            if (node->left != nullptr) {
                m_ifremove[node->left->val] = m_h;
                calcRemove(node->left, h2, inH);
            }

            if (node->right != nullptr) {
                m_ifremove[node->right->val] = m_h;
                calcRemove(node->right, h2, inH);
            }

            return;
        }
        
        calc(node->left, node->right, h2);
        calc(node->right, node->left, h2);
    }

    void calc(TreeNode* cur, TreeNode* other, int h2) {
        if (cur == nullptr) {
            return;
        }

        int hc = m_heights[cur->val];
        int ho = other == nullptr ? 0 : m_heights[other->val];
        if (hc <= ho) {
            m_ifremove[cur->val] = m_h;
            calcRemove(cur, m_h, false);
        }
        else {
            h2 = max(h2, m_h - (hc - ho));
            m_ifremove[cur->val] = h2;
            calcRemove(cur, h2, true);
        }
    }

private:
    unordered_map<int, int> m_heights;  // 每个节点的高度
    unordered_map<int, int> m_ifremove; // 如果移除的高度
    int m_h = 0;
};