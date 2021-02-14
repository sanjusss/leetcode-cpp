#include "leetcode.h"

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> conn(n + 1, vector<bool>(n + 1));
        vector<int> edgeCount(n + 1);
        for (auto& e : edges) {
            conn[e[0]][e[1]] = true;
            conn[e[1]][e[0]] = true;
            ++edgeCount[e[0]];
            ++edgeCount[e[1]];
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!conn[i][j]) {
                    continue;
                }

                for (int k = j + 1; k <= n; ++k) {
                    if (!conn[i][k] || !conn[j][k]) {
                        continue;
                    }

                    ans = min(ans, edgeCount[i] + edgeCount[j] + edgeCount[k] - 6);
                    if (ans == 0) {
                        return 0;
                    }
                }
            }
        }

        return ans == INT_MAX ? - 1 : ans;
    }
};

TEST(&Solution::minTrioDegree)