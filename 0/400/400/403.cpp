#include "leetcode.h"

// class Solution {
// public:
//     bool canCross(vector<int>& stones) {
//         int n = stones.size();
//         if (stones[1] != 1) {
//             return false;
//         }

//         if (n == 2) {
//             return true;
//         }

//         vector<unordered_set<int>> dp(n);
//         dp[1].insert(1);
//         dp[1].insert(2);

//         for (int i = 1; i < n - 1; ++i) {
//             for (int j : dp[i]) {
//                 if (j > INT_MAX - stones[i]) {
//                     continue;
//                 }

//                 int p = lower_bound(stones.begin(), stones.end(), stones[i] + j) - stones.begin();
//                 if (p == n || stones[i] + j != stones[p]) {
//                     continue;
//                 }
//                 else if (p == n - 1) {
//                     return true;
//                 }

//                 dp[p].insert(j);
//                 if (j > 1) {
//                     dp[p].insert(j - 1);
//                 }

//                 if (j < INT_MAX) {
//                     dp[p].insert(j + 1);
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; ++i) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }

        vector<vector<bool>> dp(n, vector<bool>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int step = stones[i] - stones[j];
                if (step > j + 1) {
                    continue;
                }

                dp[i][step] = dp[j][step] || dp[j][step + 1] || dp[j][step - 1];
                if (i == n - 1 && dp[i][step]) {
                    return true;
                }
            }
        }

        return false;
    }
};

TEST(&Solution::canCross)