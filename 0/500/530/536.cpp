/*
 * @Author: sanjusss
 * @Date: 2022-11-11 08:47:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-11 09:06:02
 * @FilePath: \0\500\530\536.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* str2tree(string s) {
        TreeNode root(0);
        int64_t cur = 0;
        int sign = 1;
        stack<TreeNode*> nodes;
        nodes.push(&root);
        auto insert = [&]() {
            int val = cur * sign;
            cur = 0;
            sign = 1;
            TreeNode* node = new TreeNode(val);
            if (nodes.top()->left == nullptr) {
                nodes.top()->left = node;
            }
            else {
                nodes.top()->right = node;
            }

            nodes.push(node);
        };
        char prev = 0;
        for (char i : s) {
            if (i == '(') {
                if (prev != ')') {
                    insert();
                }
            }
            else if (i == ')') {
                if (prev != ')') {
                    insert();
                }

                nodes.pop();
            }
            else if (i == '-') {
                sign = -1;
            }
            else {
                cur = cur * 10 + i - '0';
            }

            prev = i;
        }

        if (!s.empty() && s.back() != ')') {
            insert();
        }

        return root.left;
    }
};

TEST(&Solution::str2tree)