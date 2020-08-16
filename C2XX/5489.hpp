#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int maxDistance(vector<int>& position, int m) {
//        if (m <= 1) {
//            return 0;
//        }
//
//        sort(position.begin(), position.end());
//        if (m == 2) {
//            return position.back() - position.front();
//        }
//
//        int n = position.size();
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//        for (int i = 1; i < n; ++i) {
//            dp[i + 1][2] = position[i] - position[0];
//        }
//
//        for (int i = 2; i <= n; ++i) {
//            for (int j = 2; j <= m; ++j) {
//                for (int k = j - 1; k <= i; ++k) {
//                    dp[i][j] = max(dp[i][j], min(dp[k][j - 1], position[i - 1] - position[k - 1]));
//                }
//            }
//        }
//
//        return dp[n][m];
//    }
//};

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        if (m <= 1) {
            return 0;
        }

        sort(position.begin(), position.end());
        if (m == 2) {
            return position.back() - position.front();
        }

        int left = 1;
        int right = position.back() - position.front();
        int mid;
        while (left < right) {
            mid = (right - left + 1) / 2 + left;
            if (check(position, m, mid)) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }

private:
    bool check(vector<int>& position, int m, int ans) {
        int last = position[0];
        int count = 1;
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - last >= ans) {
                ++count;
                last = position[i];
                if (count >= m) {
                    return true;
                }
            }
        }

        return false;
    }
};