#include "leetcode.h"

// class Solution {
// public:
//     int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int ans = INT_MIN;
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 dp[i + 1][j + 1] = matrix[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
//                 for (int bi = i; bi >= 0; --bi) {
//                     for (int bj = j; bj >= 0; --bj) {
//                         int temp = dp[i + 1][j + 1] + dp[bi][bj] - dp[i + 1][bj] - dp[bi][j + 1];
//                         if (temp == k) {
//                             return k;
//                         }
//                         else if (temp < k) {
//                             ans = max(ans, temp);
//                         }
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
        if (n > m) {
            vector<int> sum(n);
            for (int i = 0; i < m; ++i) {
                fill(sum.begin(), sum.end(), 0);
                for (int j = i; j < m; ++j) {
                    set<int> st{ 0 };
                    int current = 0;
                    for (int c = 0; c < n; ++c) {
                        sum[c] += matrix[j][c];
                        current += sum[c];
                        auto p = st.lower_bound(current - k);
                        if (p != st.end()) {
                            ans = max(ans, current - *p);
                        }

                        st.insert(current);
                    }
                }
            }
        }
        else {
            vector<int> sum(m);
            for (int i = 0; i < n; ++i) {
                fill(sum.begin(), sum.end(), 0);
                for (int j = i; j < n; ++j) {
                    set<int> st{ 0 };
                    int current = 0;
                    for (int c = 0; c < m; ++c) {
                        sum[c] += matrix[c][j];
                        current += sum[c];
                        auto p = st.lower_bound(current - k);
                        if (p != st.end()) {
                            ans = max(ans, current - *p);
                        }

                        st.insert(current);
                    }
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::maxSumSubmatrix)