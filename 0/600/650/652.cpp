/*
 * @Author: sanjusss
 * @Date: 2022-09-05 14:41:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-05 15:50:49
 * @FilePath: \0\600\650\652.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         dfs(root);
//         return { m_Ans.begin(), m_Ans.end() };
//     }

// private:
//     template <typename T>
//     inline void hash_combine(size_t& seed, const T& val) {
//         seed ^= hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//     }

//     bool equal(TreeNode* a, TreeNode* b) {
//         if (a == nullptr && b == nullptr) {
//             return true;
//         }
//         else if (a == nullptr || b == nullptr) {
//             return false;
//         }

//         if (a->val != b->val) {
//             return false;
//         }

//         return equal(a->left, b->left) && equal(a->right, b->right);
//     }

//     size_t dfs(TreeNode* node) {
//         if (node == nullptr) {
//             return 1e9 + 7;
//         }

//         size_t code = 0;
//         hash_combine(code, node->val);
//         hash_combine(code, dfs(node->left));
//         hash_combine(code, dfs(node->right));
//         bool find = false;
//         for (auto &[_, vec] : m_Nodes) {
//             for (auto b : vec) {
//                 if (equal(node, b)) {
//                     find = true;
//                     m_Ans.insert(b);
//                 }
//             }
//         }

//         if (!find) {
//             m_Nodes[code].push_back(node);
//         }

//         return code;
//     }

// private:
//     unordered_map<size_t, vector<TreeNode*>> m_Nodes;
//     unordered_set<TreeNode*> m_Ans;
// };

class Solution {
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        dfs(root);
        return { m_Ans.begin(), m_Ans.end() };
    }

private:
    int dfs(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);
        auto tp = make_tuple(node->val, left, right);
        auto p = m_Trees.find(tp);
        if (p == m_Trees.end()) {
            m_Trees.emplace(tp, make_tuple(node, ++m_Index));
            return m_Index;
        }
        else {
            m_Ans.insert(get<0>(p->second));
            return get<1>(p->second);
        }
    }

private:
    map<tuple<int, int, int>, tuple<TreeNode *, int>> m_Trees;
    unordered_set<TreeNode *> m_Ans;

    int m_Index = 0;
};