#include "leetcode.h"

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        insert(root);
    }
    
    int next() {
        TreeNode* node = m_stack.top();
        m_stack.pop();
        insert(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !m_stack.empty();
    }

private:
    void insert(TreeNode* node) {
        while (node != nullptr) {
            m_stack.push(node);
            node = node->left;
        }
    }

private:
    stack<TreeNode*> m_stack;
};