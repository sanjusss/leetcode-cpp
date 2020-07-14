#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int minimumTotal(vector<vector<int>>& triangle) {
//        int n = triangle.size();
//        if (n == 0) {
//            return 0;
//        }
//
//        vector<vector<int>> dp(2, vector<int>(n));
//        dp[0][0] = triangle[0][0];
//        for (int i = 1; i < n; ++i) {
//            dp[i & 1][0] = triangle[i][0] + dp[(i - 1) & 1][0];
//            dp[i & 1][i] = triangle[i][i] + dp[(i - 1) & 1][i - 1];
//            for (int j = 1; j < i; ++j) {
//                dp[i & 1][j] = triangle[i][j] + min(dp[(i - 1) & 1][j - 1], dp[(i - 1) & 1][j]);
//            }
//        }
//
//        return *min_element(dp[(n - 1) & 1].begin(), dp[(n - 1) & 1].end());
//    }
//};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) {
            return 0;
        }

        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }

            dp[0] += triangle[i][0];
        }

        return *min_element(dp.begin(), dp.end());
    }
};