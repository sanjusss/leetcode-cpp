/*
 * @Author: sanjusss
 * @Date: 2021-06-30 08:21:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-30 08:43:30
 * @FilePath: \jianzhioffer\37.cpp
 */
#include "leetcode.h"

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ans = "["s;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                ans += "null"s;
            }
            else {
                ans += to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }

            ans.push_back(',');
        }

        ans.back() = ']';
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        int i = 1;
        int n = data.size() - 2;
        queue<TreeNode*> q;
        while (i <= n) {
            if (data[i] == ',') {
                ++i;
                continue;
            }

            TreeNode* node;
            if (data[i] == 'n') {
                node = nullptr;
                i += 4;
            }
            else {
                node = new TreeNode(0);
                int sign;
                if (data[i] == '-') {
                    sign = -1;
                    ++i;
                }
                else {
                    sign = 1;
                }

                do {
                    node->val = node->val * 10 + data[i] - '0';
                } while (data[++i] != ',');
                node->val *= sign;
                q.push(node);
                q.push(node);
            }

            if (root == nullptr) {
                root = node;
            }
            else {
                TreeNode* parent = q.front();
                q.pop();
                if (!q.empty() && parent == q.front()) {
                    parent->left = node;
                }
                else {
                    parent->right = node;
                }
            }
        }

        return root;
    }
};