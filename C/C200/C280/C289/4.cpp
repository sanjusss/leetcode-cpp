
#include "leetcode.h"

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        vector<int> in(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] >= 0) {
                children[parent[i]].push_back(i);
                ++in[parent[i]];
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        int ans = 0;
        vector<int> sub(n, 1); // 从i开始的最长分支
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int child1 = 0;
            int child2 = 0;
            for (int j : children[i]) {
                if (s[i] == s[j]) {
                    continue;
                }

                sub[i] = max(sub[i], 1 + sub[j]);
                if (sub[j] > child1) {
                    child2 = child1;
                    child1 = sub[j];
                }
                else if (sub[j] > child2) {
                    child2 = sub[j];
                }
            }

            ans = max(ans, child1 + child2 + 1);

            int p = parent[i];
            if (p >= 0 && --in[p] == 0) {
                q.push(p);
            }
        }

        return ans;
    }
};

TEST(&Solution::longestPath)