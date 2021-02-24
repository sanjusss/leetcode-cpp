#include "leetcode.h"

// class Solution {
// public:
//     string shortestSuperstring(vector<string>& words) {
//         int n = words.size();
//         vector<string_view> views(n);
//         for (int i = 0; i < n; ++i) {
//             views[i] = words[i];
//         }

//         vector<vector<int>> dis(n, vector<int>(n));
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (i == j) {
//                     continue;
//                 }

//                 string_view& vi = views[i];
//                 string_view& vj = views[j];
//                 for (int d = min(vi.size(), vj.size()); d > 0; --d) {
//                     if (vi.substr(vi.size() - d) == vj.substr(0, d)) {
//                         dis[i][j] = d;
//                         break;
//                     }
//                 }
//             }
//         }

//         vector<int> orders(n);
//         iota(orders.begin(), orders.end(), 0);
//         vector<int> resultOrder(n);
//         int maxSame = -1;
//         do {
//             int cur = 0;
//             for (int i = 1; i < n; ++i) {
//                 cur += dis[orders[i - 1]][orders[i]];
//             }

//             if (cur > maxSame) {
//                 maxSame = cur;
//                 copy(orders.begin(), orders.end(), resultOrder.begin());
//             }
//         } while (next_permutation(orders.begin(), orders.end()));

//         string ans(views[resultOrder[0]]);
//         for (int i = 1; i < n; ++i) {
//             ans += string(views[resultOrder[i]].substr(dis[resultOrder[i - 1]][resultOrder[i]]));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<string_view> views(n);
        for (int i = 0; i < n; ++i) {
            views[i] = words[i];
        }

        vector<vector<int>> same(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }

                string_view& vi = views[i];
                string_view& vj = views[j];
                for (int d = min(vi.size(), vj.size()); d > 0; --d) {
                    if (vi.substr(vi.size() - d) == vj.substr(0, d)) {
                        same[i][j] = d;
                        break;
                    }
                }
            }
        }

        int maxMask = (1 << n) - 1;
        vector<vector<int>> dp(maxMask + 1, vector<int>(n));
        vector<vector<int>> front(maxMask + 1, vector<int>(n, -1));
        for (int mask = 0; mask <= maxMask; ++mask) {
            for (int cur = 0; cur < n; ++cur) {
                if (!(mask & (1 << cur))) {
                    continue;
                }

                int prevMask = mask ^ (1 << cur);
                for (int prev = 0; prev < n; ++prev) {
                    if (!(prevMask & (1 << prev))) {
                        continue;
                    }

                    int val = dp[prevMask][prev] + same[prev][cur];
                    if (front[mask][cur] == -1 || val > dp[mask][cur]) {
                        dp[mask][cur] = val;
                        front[mask][cur] = prev;
                    }
                }
            }
        }

        int cur = max_element(dp[maxMask].begin(), dp[maxMask].end()) - dp[maxMask].begin();
        string ans = words[cur];
        int mask = maxMask;
        while (front[mask][cur] != -1) {
            int prev = front[mask][cur];
            ans = words[prev].substr(0, words[prev].size() - same[prev][cur]) + ans;
            mask = mask ^ (1 << cur);
            cur = prev;
        }

        return ans;
    }
};

TEST(&Solution::shortestSuperstring)