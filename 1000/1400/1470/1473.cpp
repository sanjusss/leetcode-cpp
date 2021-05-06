#include "leetcode.h"

// class Solution {
// public:
//     int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
//         vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, INT_MAX)));
//         fill(dp[0][0].begin(), dp[0][0].end(), 0);
//         for (int i = 0; i < m; ++i) {
//             for (int t = 1; t <= target; ++t) {
//                 if (houses[i] == 0) {//需要上色
//                     for (int j = 1; j <= n; ++j) {//前一个街区的颜色
//                         for (int k = 1; k <= n; ++k) { //当前街区的颜色
//                             if (j == k) {//颜色相同
//                                 if (dp[i][t][j] != INT_MAX) {
//                                     dp[i + 1][t][k] = min(dp[i + 1][t][k], dp[i][t][j] + cost[i][k - 1]);
//                                 }
//                             }
//                             else {//颜色不同
//                                 if (dp[i][t - 1][j] != INT_MAX) {
//                                     dp[i + 1][t][k] = min(dp[i + 1][t][k], dp[i][t - 1][j] + cost[i][k - 1]);
//                                 }
//                             }
//                         }
//                     }
//                 }
//                 else {//不需要上色
//                     int c = houses[i];
//                     dp[i + 1][t][c] = dp[i][t][c];
//                     for (int j = 1; j <= n; ++j) {
//                         if (j == c) {
//                             continue;
//                         }

//                         dp[i + 1][t][c] = min(dp[i + 1][t][c], dp[i][t - 1][j]);
//                     }
//                 }
//             }
//         }

//         int ans = *min_element(dp[m][target].begin(), dp[m][target].end());
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

// class Solution {
// public:
//     int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
//         vector<vector<int>> dpPrev(target + 1, vector<int>(n + 1, INT_MAX));
//         vector<vector<int>> dpCur(target + 1, vector<int>(n + 1));
//         fill(dpPrev[0].begin(), dpPrev[0].end(), 0);
//         for (int i = 0; i < m; ++i) {
//             fill(dpCur[0].begin(), dpCur[0].end(), INT_MAX);
//             for (int t = 1; t <= target; ++t) {
//                 fill(dpCur[t].begin(), dpCur[t].end(), INT_MAX);
//                 if (houses[i] == 0) {//需要上色
//                     for (int j = 1; j <= n; ++j) {//前一个街区的颜色
//                         for (int k = 1; k <= n; ++k) { //当前街区的颜色
//                             if (j == k) {//颜色相同
//                                 if (dpPrev[t][j] != INT_MAX) {
//                                     dpCur[t][k] = min(dpCur[t][k], dpPrev[t][j] + cost[i][k - 1]);
//                                 }
//                             }
//                             else {//颜色不同
//                                 if (dpPrev[t - 1][j] != INT_MAX) {
//                                     dpCur[t][k] = min(dpCur[t][k], dpPrev[t - 1][j] + cost[i][k - 1]);
//                                 }
//                             }
//                         }
//                     }
//                 }
//                 else {//不需要上色
//                     int c = houses[i];
//                     dpCur[t][c] = dpPrev[t][c];
//                     for (int j = 1; j <= n; ++j) {
//                         if (j == c) {
//                             continue;
//                         }

//                         dpCur[t][c] = min(dpCur[t][c], dpPrev[t - 1][j]);
//                     }
//                 }
//             }

//             swap(dpPrev, dpCur);
//         }

//         int ans = *min_element(dpPrev[target].begin(), dpPrev[target].end());
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<int>> dpPrev(target + 1, vector<int>(n + 1, INT_MAX));
        vector<vector<int>> dpCur(target + 1, vector<int>(n + 1));
        vector<int> min0Prev(target + 1);
        vector<int> min0Cur(target + 1);
        vector<int> min1Prev(target + 1);
        vector<int> min1Cur(target + 1);

        fill(dpPrev[0].begin(), dpPrev[0].end(), 0);
        for (int i = 0; i < m; ++i) {
            fill(dpCur[0].begin(), dpCur[0].end(), INT_MAX);
            fill(min0Cur.begin(), min0Cur.end(), 0);
            fill(min1Cur.begin(), min1Cur.end(), 0);
            for (int t = 1; t <= target; ++t) {
                fill(dpCur[t].begin(), dpCur[t].end(), INT_MAX);
                if (houses[i] == 0) {                   //需要上色
                    for (int c = 1; c <= n; ++c) {
                        //颜色相同
                        if (dpPrev[t][c] != INT_MAX) {
                            dpCur[t][c] = dpPrev[t][c] + cost[i][c - 1]; 
                        }

                        //颜色不同
                        if (min0Prev[t - 1] > 0 || i == 0) {
                            if (min0Prev[t - 1] == c) {
                                if (min1Prev[t - 1] > 0 && dpPrev[t - 1][min1Prev[t - 1]] != INT_MAX) {
                                    dpCur[t][c] = min(dpCur[t][c], dpPrev[t - 1][min1Prev[t - 1]] + cost[i][c - 1]);
                                }
                            }
                            else if (dpPrev[t - 1][min0Prev[t - 1]] != INT_MAX) {
                                dpCur[t][c] = min(dpCur[t][c], dpPrev[t - 1][min0Prev[t - 1]] + cost[i][c - 1]);
                            }
                        }

                        if (dpCur[t][c] < dpCur[t][min0Cur[t]]) {
                            min1Cur[t] = min0Cur[t];
                            min0Cur[t] = c;
                        }
                        else if (dpCur[t][c] < dpCur[t][min1Cur[t]]) {
                            min1Cur[t] = c;
                        }
                    }
                }
                else {  //不需要上色
                    int c = houses[i];
                    dpCur[t][c] = dpPrev[t][c];
                    if (min0Prev[t - 1] > 0 || i == 0) {
                        if (min0Prev[t - 1] == c) {
                            if (min1Prev[t - 1] > 0) {
                                dpCur[t][c] = min(dpCur[t][c], dpPrev[t - 1][min1Prev[t - 1]]);
                            }
                        }
                        else {
                            dpCur[t][c] = min(dpCur[t][c], dpPrev[t - 1][min0Prev[t - 1]]);
                        }
                    }

                    min0Cur[t] = c;
                    min1Cur[t] = 0;
                }
            }

            swap(dpPrev, dpCur);
            swap(min0Cur, min0Prev);
            swap(min1Cur, min1Prev);
        }

        int ans = *min_element(dpPrev[target].begin(), dpPrev[target].end());
        return ans == INT_MAX ? -1 : ans;
    }
};

TEST(&Solution::minCost)