/*
 * @Author: sanjusss
 * @Date: 2022-07-25 08:26:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-25 08:31:21
 * @FilePath: \0\900\910\919.cpp
 */
#include "leetcode.h"

class CBTInserter {
public:
    CBTInserter(TreeNode* root) : m_root(root) {
        m_q.push(root);
    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        while (!m_q.empty()) {
            auto parent = m_q.front();
            if (parent->left == nullptr) {
                parent->left = node;
                return parent->val;
            }
            else if (parent->right == nullptr) {
                parent->right = node;
                return parent->val;
            }
            else {
                m_q.push(parent->left);
                m_q.push(parent->right);
                m_q.pop();
            }
        }

        return -1;
    }
    
    TreeNode* get_root() {
        return m_root;
    }

private:
    TreeNode* m_root;
    queue<TreeNode*> m_q;
};