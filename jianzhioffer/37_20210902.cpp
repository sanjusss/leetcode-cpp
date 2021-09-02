/*
 * @Author: sanjusss
 * @Date: 2021-09-02 08:31:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-02 08:51:47
 * @FilePath: \jianzhioffer\37_20210902.cpp
 */
#include "leetcode.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                ans += "null,"s;
            }
            else {
                ans += to_string(node->val);
                ans.push_back(',');
                q.push(node->left);
                q.push(node->right);
            }
        }

        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<reference_wrapper<TreeNode*>> q;
        q.push(ref(root));
        size_t prev = 0;
        while (prev != string::npos) {
            size_t cur = data.find(',', prev);
            string sub;
            if (cur == string::npos) {
                sub = data.substr(prev);
                prev = string::npos;
            }
            else {
                sub = data.substr(prev, cur - prev);
                prev = cur +1;
            }

            auto& node = q.front().get();
            q.pop();
            if (sub == "null"s) {
                node = nullptr;
            }
            else {
                node = new TreeNode(stoi(sub));
                q.push(ref(node->left));
                q.push(ref(node->right));
            }
        }
        
        return root;
    }
};
