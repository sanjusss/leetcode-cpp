#include "leetcode.h"

// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         return check(s1, s2);
//     }

// private:
//     bool check(string_view s1, string_view s2) {
//         if (s1 == s2) {
//             return true;
//         }

//         int n = s1.size();
//         for (int i = 1; i < n; ++i) {
//             if ((check(s1.substr(0, i), s2.substr(0, i)) && check(s1.substr(i, n - i), s2.substr(i, n - i))) ||
//             (check(s1.substr(0, i), s2.substr(n - i, i)) && check(s1.substr(i, n - i), s2.substr(0, n - i)))) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };

// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         int n = s1.size();
//         vector<vector<vector<vector<bool>>>> dp(
//             n, vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n))));
//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = i; j < n; ++j) {
//                 int dis = j - i;
//                 for (int k = n - 1 - dis; k >= 0; --k) {
//                     int l = k + dis;
//                     if (i == j) {
//                         dp[i][j][k][l] = s1[i] == s2[k];
//                         continue;
//                     }

//                     for (int m = 0; m < dis && !dp[i][j][k][l]; ++m) {
//                         dp[i][j][k][l] = dp[i][j][k][l] || 
//                         (dp[i][i + m][k][k + m] && dp[i + m + 1][j][k + m + 1][l]) ||
//                         (dp[i][i + m][l - m][l] && dp[i + m + 1][j][k][k + dis - m - 1]);
//                     }
//                 }
//             }
//         }

//         return dp[0][n - 1][0][n - 1];
//     }
// };

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j][1] = s1[i] == s2[j];
                int maxK = n - max(i, j);
                for (int k = 2; k <= maxK; ++k) {
                    for (int l = 1; l < k && !dp[i][j][k]; ++l) {
                        dp[i][j][k] = (dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i][j + k - l][l] && dp[i + l][j][k - l]);
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};

TEST(&Solution::isScramble)