#include "leetcode.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int tlen = t.size();
        vector<vector<int>> c2p(CHAR_MAX + 1);
        for (int i = 0; i < tlen; ++i) {
            c2p[t[i]].push_back(i);
        }

        vector<int64_t> dp(tlen + 1);
        dp[0] = 1;
        for (char i : s) {
            if (c2p[i].empty()) {
                continue;
            }

            for (int j = c2p[i].size() - 1; j >= 0; --j) {
                dp[c2p[i][j] + 1] += dp[c2p[i][j]];
            }
        }

        return dp[tlen];
    }
};

TEST(&Solution::numDistinct)