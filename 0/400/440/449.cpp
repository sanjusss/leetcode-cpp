/*
 * @Author: sanjusss
 * @Date: 2022-05-11 10:50:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-11 11:27:41
 * @FilePath: \0\400\440\449.cpp
 */
#include "leetcode.h"

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node == nullptr) {
                continue;
            }

            ans += to_string(node->val) + ',';
            s.push(node->right);
            s.push(node->left);
        }

        if (!ans.empty()) {
            ans.pop_back();
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        stack<TreeNode*> s;
        TreeNode* root = nullptr;
        int n = data.size();
        int val = 0;
        for (int i = 0; i <= n; ++i) {
            if (i < n && data[i] != ',') {
                val = val * 10 + data[i] - '0';
                continue;
            }

            TreeNode* cur = new TreeNode(val);
            while (!s.empty()) {
                auto prev = s.top();
                if (prev->val < val) {
                    s.pop();
                    if (s.empty() || s.top()->val > val) {
                        prev->right = cur;
                        break;
                    }
                }
                else {
                    prev->left = cur;
                    break;
                }
            }

            s.push(cur);
            if (root == nullptr) {
                root = cur;
            }

            val = 0;
        }

        return root;
    }
};