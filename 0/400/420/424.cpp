#include "leetcode.h"

// O(kn)
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         vector<vector<int>> dp(k + 1, vector<int>(26));
//         int ans = 0;
//         for (char c : s) {
//             int v = c - 'A';

//             for (int i = k; i >= 1; --i) {
//                 for (int j = 0; j < 26; ++j) {
//                     if (j == v) {
//                         ++dp[i][j];
//                     }
//                     else {
//                         dp[i][j] = dp[i - 1][j] + 1;
//                     }

//                     ans = max(ans, dp[i][j]);
//                 }
//             }

//             for (int j = 0; j < 26; ++j) {
//                 if (j == v) {
//                     ans = max(ans, ++dp[0][j]);
//                 }
//                 else {
//                     dp[0][j] = 0;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        array<int, 26> cnt = { 0 };
        int current = 0;
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < n) {
            current = max(current, ++cnt[s[right] - 'A']);
            if (right - left + 1 - current > k) {
                --cnt[s[left] - 'A'];
                ++left;
            }

            ans = max(ans, right - left + 1);
            ++right;
        }

        return ans;
    }
};

TEST(&Solution::characterReplacement)