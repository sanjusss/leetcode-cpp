/*
 * @Author: sanjusss
 * @Date: 2022-06-19 11:35:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-19 11:51:58
 * @FilePath: \0\500\500\508.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<TreeNode*, int> sum;
        unordered_map<int, int> cnt;
        stack<pair<TreeNode*, TreeNode*>> s;
        s.emplace(root, nullptr);
        sum[nullptr] = 0;
        while (!s.empty()) {
            auto[node, parent] = s.top();
            if (sum.count(node)) {
                if (node != nullptr) {
                    sum[node] += node->val;
                    ++cnt[sum[node]];
                }

                if (parent != nullptr) {
                    sum[parent] += sum[node];
                }

                s.pop();
            }
            else {
                s.emplace(node->left, node);
                s.emplace(node->right, node);
            }
        }

        vector<int> ans;
        int maxCnt = 0;
        for (auto [sum, c] : cnt) {
            if (c > maxCnt) {
                ans.clear();
                ans.push_back(sum);
                maxCnt = c;
            }
            else if (c == maxCnt) {
                ans.push_back(sum);
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::findFrequentTreeSum)