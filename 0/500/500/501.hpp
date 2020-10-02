#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    vector<int> findMode(TreeNode* root) {
//        unordered_map<int, int> counts;
//        calc(root, counts);
//        vector<int> ans;
//        int cur = 0;
//        for (auto& p : counts) {
//            if (ans.empty()) {
//                ans.push_back(p.first);
//                cur = p.second;
//            }
//            else {
//                if (cur == p.second) {
//                    ans.push_back(p.first);
//                }
//                else if (p.second > cur){
//                    ans.clear();
//                    ans.push_back(p.first);
//                    cur = p.second;
//                }
//            }
//        }
//
//        return ans;
//    }
//
//private:
//    void calc(TreeNode* node, unordered_map<int, int>& counts) {
//        if (node == nullptr) {
//            return;
//        }
//
//        ++counts[node->val];
//        calc(node->left, counts);
//        calc(node->right, counts);
//    }
//};

//class Solution {
//public:
//    vector<int> findMode(TreeNode* root) {
//        dfs(root);
//        appendCurNode();
//        return m_ans;
//    }
//
//private:
//    void dfs(TreeNode* node) {
//        if (node == nullptr) {
//            return;
//        }
//
//        dfs(node->left);
//
//        if (m_curNode != nullptr && m_curNode->val == node->val) {
//            ++m_curCount;
//        }
//        else {
//            appendCurNode();
//            m_curNode = node;
//            m_curCount = 1;
//        }
//
//        dfs(node->right);
//    }
//
//    void appendCurNode() {
//        if (m_curNode == nullptr) {
//            return;
//        }
//
//        if (m_curCount == m_max) {
//            m_ans.push_back(m_curNode->val);
//        }
//        else if (m_curCount > m_max) {
//            m_max = m_curCount;
//            if (m_ans.size() == 1) {
//                m_ans.back() = m_curNode->val;
//            }
//            else {
//                m_ans.clear();
//                m_ans.push_back(m_curNode->val);
//            }
//        }
//    }
//
//private:
//    vector<int> m_ans;
//    int m_max = 0;
//    TreeNode* m_curNode = nullptr;
//    int m_curCount = 0;
//};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxCount = 0;
        int cur = 0;
        int curCount = 0;

        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            if (curCount == 0) {
                cur = root->val;
                curCount = 1;
            }
            else if (cur == root->val) {
                ++curCount;
            }
            else {
                if (curCount == maxCount) {
                    ans.push_back(cur);
                }
                else if (curCount > maxCount) {
                    maxCount = curCount;
                    ans.clear();
                    ans.push_back(cur);
                }

                cur = root->val;
                curCount = 1;
            }

            root = root->right;
        }

        if (curCount > 0) {
            if (curCount > maxCount) {
                ans.clear();
                ans.push_back(cur);
            }
            else if (curCount == maxCount) {
                ans.push_back(cur);
            }
        }

        return ans;
    }
};