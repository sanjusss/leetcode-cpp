#include "leetcode.h"

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> conns(n);
        for (auto &e : edges) {
            conns[e[0]].push_back(e[1]);
            conns[e[1]].push_back(e[0]);
        }

        vector<int> freq(n);
        vector<bool> visit(n);
        function<bool(int, int)> dfsFreq = [&] (int cur, int stop) -> bool {
            if (visit[cur]) {
                return false;
            }

            visit[cur] = true;
            ++freq[cur];
            bool res = false;
            if (cur != stop) {
                for (int nxt : conns[cur]) {
                    if (dfsFreq(nxt, stop)) {
                        res = true;
                        break;
                    }
                }
            }
            else {
                res = true;
            }

            visit[cur] = false;
            if (!res) {
                --freq[cur];
            }

            return res;
        };
        for (auto& t : trips) {
            dfsFreq(t[0], t[1]);
        }

        vector<vector<int>> dp(n, vector<int>(2, -1));
        function<int(int, int)> dfsPrice = [&] (int i, int parentIsHalf) -> int {
            for (int k = 0; k < 2; ++k) {
                if (dp[i][k] >= 0) {
                    continue;
                }

                dp[i][k] = (k ? price[i] / 2 : price[i]) * freq[i];
                for (int j : conns[i]) {
                    if (visit[j]) {
                        continue;
                    }

                    visit[j] = true;
                    dp[i][k] += dfsPrice(j, k);
                    visit[j] = false;
                }
            }

            if (parentIsHalf) {
                return dp[i][0];
            }
            else {
                return min(dp[i][0], dp[i][1]);
            }
        };
        visit[0] = true;
        return dfsPrice(0, 0);
    }
};

TEST(&Solution::minimumTotalPrice)