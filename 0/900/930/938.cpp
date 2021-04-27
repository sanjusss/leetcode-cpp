#include "leetcode.h"

// class Solution {
// public:
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         if (root == nullptr) {
//             return 0;
//         }

//         int ans = 0;
//         if (root->val >= low && root->val <= high) {
//             ans += root->val;
//         }

//         if (root->val >= low) {
//             ans += rangeSumBST(root->left, low, high);
//         }

//         if (root->val <= high) {
//             ans += rangeSumBST(root->right, low, high);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node == nullptr) {
                continue;
            }

            if (node->val < low) {
                s.push(node->right);
            }
            else if (node->val > high) {
                s.push(node->left);
            }
            else {
                ans += node->val;
                s.push(node->left);
                s.push(node->right);
            }
        }

        return ans;
    }
};

TEST(&Solution::rangeSumBST)