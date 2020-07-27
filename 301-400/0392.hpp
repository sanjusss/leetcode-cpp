#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    bool isSubsequence(string s, string t) {
//        int sl = s.size();
//        int tl = t.size();
//        vector<vector<bool>> dp(sl + 1, vector<bool>(tl + 1));
//        fill(dp[0].begin(), dp[0].end(), true);
//        for (int i = 0; i < sl; ++i) {
//            for (int j = 0; j < tl; ++j) {
//                dp[i + 1][j + 1] = dp[i + 1][j] || (dp[i][j] && s[i] == t[j]);
//            }
//        }
//
//        return dp[sl][tl];
//    }
//};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.size();
        int tl = t.size();
        int si = 0;
        int ti = 0;
        while (si < sl && ti < tl) {
            if (s[si] == t[ti]) {
                ++si;
            }

            ++ti;
        }

        return si == sl;
    }
};