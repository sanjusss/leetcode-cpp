#include "leetcode.h"

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1;
        s1.push(root1);
        stack<TreeNode*> s2;
        s2.push(root2);

        while (!s1.empty() && !s2.empty()) {
            TreeNode* node1 = nullptr;
            while (!s1.empty()) {
                node1 = s1.top();
                s1.pop();
                if (node1->left == nullptr && node1->right == nullptr) {
                    break;
                }
                else {
                    if (node1->right != nullptr) {
                        s1.push(node1->right);
                    }

                    if (node1->left != nullptr) {
                        s1.push(node1->left);
                    }
                }
            }

            TreeNode* node2 = nullptr;
            while (!s2.empty()) {
                node2 = s2.top();
                s2.pop();
                if (node2->left == nullptr && node2->right == nullptr) {
                    break;
                }
                else {
                    if (node2->right != nullptr) {
                        s2.push(node2->right);
                    }

                    if (node2->left != nullptr) {
                        s2.push(node2->left);
                    }
                }
            }

            if (node1 == nullptr && node2 == nullptr) {
                break;
            }

            if (node1 == nullptr || node2 == nullptr || node1->val != node2->val) {
                return false;
            }
        }

        return s1.empty() && s2.empty();
    }
};

TEST(&Solution::leafSimilar)