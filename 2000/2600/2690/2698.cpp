#include "leetcode.h"

class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int v = i * i;
            vector<int> bits;
            for (int j = v; j > 0; j /= 10) {
                bits.push_back(j % 10);
            }

            reverse(bits.begin(), bits.end());
            int blen = bits.size();
            bool found = false;
            vector<unordered_set<int>> dp(blen + 1);
            dp[0].insert(0);
            for (int j = 0; j < blen; ++j) {
                int d = 0;
                int b = 1;
                for (int k = j; k >= 0; --k) {
                    d += bits[k] * b;
                    b *= 10;
                    if (d > v) {
                        break;
                    }

                    for (int l : dp[k]) {
                        if (d + l <= i) {
                            dp[j + 1].insert(d + l);
                        }
                    }
                }
            }

            if (dp[blen].count(i)) {
                ans += v;
            }
        }

        return ans;
    }
};

TEST(&Solution::punishmentNumber)