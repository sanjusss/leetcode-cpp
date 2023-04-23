/*
 * @Author: sanjusss
 * @Date: 2023-04-23 09:25:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-23 09:45:54
 * @FilePath: \1000\1100\1100\1105.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int w = 0;
            int h = 0;
            for (int j = i; j >= 0 && w + books[j][0] <= shelfWidth; --j) {
                w += books[j][0];
                h = max(h, books[j][1]);
                dp[i + 1] = min(dp[i + 1], dp[j] + h);
            }
        }

        return dp[n];
    }
};

TEST(&Solution::minHeightShelves)