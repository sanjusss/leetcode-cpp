/*
 * @Author: sanjusss
 * @Date: 2024-02-21 09:41:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-21 10:18:07
 * @FilePath: \0\100\100\106_20240221.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> ipos;
        for (int i = 0; i < n; ++i) {
            ipos[inorder[i]] = i;
        }

        struct Item {
            TreeNode** node;
            int ib;
            int ie;
            int pb;
            int pe;
        };
        TreeNode* ans = nullptr;
        stack<Item> s;
        s.push(Item{ &ans, 0, n, 0, n });
        while (!s.empty()) {
            Item i = s.top();
            s.pop();
            if (i.ib >= i.ie) {
                continue;
            }

            auto& node = *(i.node);
            node = new TreeNode(postorder[i.pe - 1]);
            int midi = ipos[postorder[i.pe - 1]];
            s.push(Item{ &(node->left), i.ib, midi, i.pb, i.pb + (midi - i.ib) });
            s.push(Item{ &(node->right), midi + 1, i.ie, i.pb + (midi - i.ib), i.pe - 1 });
        }

        return ans;
    }
};

TEST(&Solution::buildTree)