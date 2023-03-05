#include "leetcode.h"

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int64_t> ans;

        while (!q.empty()) {
            int64_t sum = 0;
            for (int qi = q.size(); qi > 0; --qi) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ans.push_back(sum);
        }

        if (ans.size() < k) {
            return -1;
        }

        nth_element(ans.begin(), ans.begin() + (k - 1), ans.end(), greater<int64_t>());
        return ans[k - 1];
    }
};