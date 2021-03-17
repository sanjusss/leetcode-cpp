#include "leetcode.h"

// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n  = t.size();
//         vector<int64_t> dp(n + 1);
//         dp[0] = 1;
//         for (char i : s) {
//             for (int j = n - 1; j >= 0; --j) {
//                 if (i == t[j]) {
//                     dp[j + 1] += dp[j];
//                 }
//             }
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int numDistinct(string s, string t) {
        int n  = t.size();
        vector<vector<int>> tchars(CHAR_MAX + 1);
        for (int i = n - 1; i >= 0; --i) {
            tchars[t[i]].push_back(i + 1);
        }

        vector<int64_t> dp(n + 1);
        dp[0] = 1;
        for (char i : s) {
            for (int j : tchars[i]) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n];
    }
};

TEST(&Solution::numDistinct)