/*
 * @Author: sanjusss
 * @Date: 2024-03-12 10:15:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-12 10:18:15
 * @FilePath: \1000\1200\1260\1261.cpp
 */
#include "leetcode.h"

class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            eles.insert(node->val);
            if (node->left != nullptr) {
                node->left->val = node->val * 2 + 1;
                s.push(node->left);
            }
            if (node->right != nullptr) {
                node->right->val = node->val * 2 + 2;
                s.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        return eles.count(target);
    }

private:
    unordered_set<int> eles;
};