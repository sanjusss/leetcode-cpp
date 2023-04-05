#include "leetcode.h"

// class Solution {
// public:
//     int mergeStones(vector<int>& stones, int k) {
//         int n = stones.size();
//         if ((n - 1) % (k - 1) != 0) {
//             return -1;
//         }

//         vector<int> sums(n + 1);
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + stones[i];
//         }

//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
//         function<int(int, int, int)> dfs = [&](int i, int j, int p) -> int {
//             int& res = dp[i][j][p];
//             if (res != -1) {
//                 return res;
//             }

//             if (p == 1) {
//                 if (i == j) {
//                     res = 0;
//                 }
//                 else {
//                     res = dfs(i, j, k) + sums[j + 1] - sums[i];
//                 }
//             }
//             else {
//                 res = INT_MAX;
//                 for (int t = i; t < j; t += k - 1) {
//                     res = min(res, dfs(i, t, 1) + dfs(t + 1, j, p - 1));
//                 }
//             }

//             return res;
//         };

//         return dfs(0, n - 1, 1);
//     }
// };

// class Solution {
// public:
//     int mergeStones(vector<int>& stones, int k) {
//         int n = stones.size();
//         if ((n - 1) % (k - 1) != 0) {
//             return -1;
//         }

//         vector<int> sums(n + 1);
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + stones[i];
//         }

//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         function<int(int, int)> dfs = [&](int i, int j) -> int {
//             int& res = dp[i][j];
//             if (res != -1) {
//                 return res;
//             }

//             if ((j - i) % (k - 1) == 0) {
//                 if (i == j) {
//                     res = 0;
//                 }
//                 else {
//                     res = INT_MAX;
//                     for (int t = i; t < j; t += k - 1) {
//                         res = min(res, dfs(i, t) + dfs(t + 1, j) + sums[j + 1] - sums[i]);
//                     }
//                 }
//             }
//             else {
//                 res = INT_MAX;
//                 for (int t = i; t < j; t += k - 1) {
//                     res = min(res, dfs(i, t) + dfs(t + 1, j));
//                 }
//             }

//             return res;
//         };

//         return dfs(0, n - 1);
//     }
// };

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }

        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = INT_MAX;
                for (int t = i; t < j; t += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][t] + dp[t + 1][j]);
                }

                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += sums[j + 1] - sums[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};