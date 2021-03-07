#include "leetcode.h"

// class Solution {
// public:
//     int countRestrictedPaths(int n, vector<vector<int>>& edges) {
//         vector<unordered_map<int, int>> conn(n);
//         for (auto& e : edges) {
//             conn[e[0] - 1][e[1] - 1] = e[2];
//             conn[e[1] - 1][e[0] - 1] = e[2];
//         }

//         vector<int> dist(n, INT_MAX);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.emplace(0, n - 1);
//         int distCount = 0;
//         while (distCount < n) {
//             int d;
//             int i ;
//             tie(d, i) = pq.top();
//             pq.pop();
//             if (dist[i] != INT_MAX) {
//                 continue;
//             }

//             ++distCount;
//             dist[i] = d;
//             for (auto& [j, jd] : conn[i]) {
//                 if (dist[j] == INT_MAX) {
//                     pq.emplace(d + jd, j);
//                 }
//             }
//         }

//         vector<vector<int>> nexts(n);
//         for (int i = n - 2; i >= 0; --i) {
//             for (auto& [j, _] : conn[i]) {
//                 if (dist[j] < dist[i]) {
//                     nexts[i].push_back(j);
//                 }
//             }
//         }

//         vector<int> dp(n);
//         dp[n - 1] = 1;
//         dfs(nexts, dp, 0);
//         return dp[0];
//     }

// private:
//     void dfs(const vector<vector<int>> &nexts, vector<int>& dp, int i) {
//         if (dp[i] != 0) {
//             return;
//         }

//         static const int mod = 1e9 + 7;

//         for (int j : nexts[i]) {
//             dfs(nexts, dp, j);
//             dp[i] = (dp[i] + dp[j]) % mod; 
//         }
//     }
// };

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> conn(n);
        for (auto& e : edges) {
            conn[e[0] - 1].emplace_back(e[1] - 1, e[2]);
            conn[e[1] - 1].emplace_back(e[0] - 1, e[2]);
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, n - 1);
        int distCount = 0;
        while (distCount < n) {
            int d;
            int i ;
            tie(d, i) = pq.top();
            pq.pop();
            if (dist[i] != INT_MAX) {
                continue;
            }

            ++distCount;
            dist[i] = d;
            for (auto& [j, jd] : conn[i]) {
                if (dist[j] == INT_MAX) {
                    pq.emplace(d + jd, j);
                }
            }
        }

        vector<int> orders(n);
        for (int i = 0; i < n; ++i) {
            orders[i] = i;
        }

        sort(orders.begin(), orders.end(), [&dist](int a, int b) {
            return dist[a] < dist[b];
        });
        vector<int> dp(n);
        dp[n - 1] = 1;
        static const int mod = 1e9 + 7;
        for (int i : orders) {
            for (auto& [j, _] : conn[i]) {
                if (dist[j] < dist[i]) {
                    dp[i] = (dp[i] + dp[j]) % mod;
                }
            }

            if (i == 0) {
                break;
            }
        }

        return dp[0];
    }
};

TEST(&Solution::countRestrictedPaths)