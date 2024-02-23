#include "leetcode.h"

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int64_t sum = 0;
            for (int qi = q.size(); qi > 0; --qi) {
                auto node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            pq.push(sum);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        if (pq.size() == k) {
            return pq.top();
        } else {
            return -1;
        }
    }
};