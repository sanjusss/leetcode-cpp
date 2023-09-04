#include "leetcode.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                ans.push_back('n');
            }
            else {
                for (int i = node->val; i > 0; i /= 10) {
                    ans.push_back('0' + (i % 10));
                }

                ans.push_back(',');
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode root(0);
        int n = data.size();
        queue<pair<TreeNode*, bool>> q;
        q.emplace(&root, false);
        int val = 0;
        int b = 1;
        for (char c : data) {
            if (c >= '0' && c <= '9') {
                val += b * (c - '0');
                b *= 10;
                continue;
            }

            auto [parent, isRight] = q.front();
            q.pop();
            if (c != ',') {
                continue;
            }

            TreeNode* node = new TreeNode(val);
            val = 0;
            b = 1;
            if (isRight) {
                parent->right = node;
            }
            else {
                parent->left = node;
            }

            q.emplace(node, false);
            q.emplace(node, true);
        }

        return root.left;
    }
};
