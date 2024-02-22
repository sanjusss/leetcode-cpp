/*
 * @Author: sanjusss
 * @Date: 2024-02-22 09:38:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-22 09:57:20
 * @FilePath: \0\800\880\889_20240222.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        struct Param {
            TreeNode** node;
            int preB;
            int preE;
            int postB;
            int postE;
        };

        int n = postorder.size();
        unordered_map<int, int> post2i;
        for (int i = 0; i < n; ++i) {
            post2i[postorder[i]] = i;
        }

        TreeNode* ans = nullptr;
        stack<Param> s;
        s.push(Param{ &ans, 0, n, 0, n });
        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            if (p.postB >= p.postE) {
                continue;
            }

            auto& node = *(p.node);
            node = new TreeNode(preorder[p.preB]);
            if (p.preB + 1 >= p.preE) {
                continue;
            }

            int mid = post2i[preorder[p.preB + 1]];
            s.push(Param{ &(node->left), p.preB + 1, p.preB + 1 + (mid - p.postB) + 1, p.postB, mid + 1 });
            s.push(Param{ &(node->right), p.preB + 1 + (mid - p.postB) + 1, p.preE, mid + 1, p.postE - 1 });
        }

        return ans;
    }
};