/*
 * @Author: sanjusss
 * @Date: 2022-05-01 09:02:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-01 09:16:10
 * @FilePath: \1000\1300\1300\1305.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        auto dfs = [](stack<TreeNode*>& s, TreeNode*& node) {
            TreeNode* res = nullptr;
            if (node != nullptr || !s.empty()) {
                while (node != nullptr) {
                    s.push(node);
                    node = node->left;
                }

                node = s.top();
                s.pop();
                res = node;
                node = node->right;
            }

            return res;
        };

        vector<int> ans;
        TreeNode* cur1 = dfs(s1, root1);
        TreeNode* cur2 = dfs(s2, root2);
        while (cur1 != nullptr || cur2 != nullptr) {
            if (cur2 == nullptr || (cur1 != nullptr && cur1->val < cur2->val)) {
                ans.push_back(cur1->val);
                cur1 = dfs(s1, root1);
            }
            else {
                ans.push_back(cur2->val);
                cur2 = dfs(s2, root2);
            }
        }

        return ans;
    }
};