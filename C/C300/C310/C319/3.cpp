/*
 * @Author: sanjusss
 * @Date: 2022-11-13 10:26:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-13 10:52:36
 * @FilePath: \C\C300\C310\C319\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> src;
            for (int qi = q.size(); qi > 0; --qi) {
                auto node = q.front();
                q.pop();
                src.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            vector<int> des = src;
            sort(des.begin(), des.end());
            
            int n = src.size();
            unordered_map<int, int> pos;
            for (int i = 0; i < n; ++i) {
                pos[src[i]] = i;
            }

            for (int i = 0; i < n; ++i) {
                if (src[i] == des[i]) {
                    continue;
                }

                int j = pos[des[i]];
                swap(src[i], src[j]);
                pos[src[i]] = i;
                pos[src[j]] = j;
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::minimumOperations)