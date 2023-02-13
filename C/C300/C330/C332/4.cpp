/*
 * @Author: sanjusss
 * @Date: 2023-02-12 11:09:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-12 13:58:55
 * @FilePath: \C\C300\C330\C332\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumScore(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> lefts(n, m);
        for (int i = 0, j = 0; i < m && j < n; ++i) {
            if (s[i] == t[j]) {
                lefts[j++] = i;
            }
        }

        if (lefts[n - 1] != m) {
            return 0;
        }

        vector<int> rights(n, -1);
        int r = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] == t[r]) {
                rights[r--] = i;
            }
        }

        int ans = ++r;
        for (int l = 0; l < n && lefts[l] < m; ++l) {
            while (rights[r - 1] > lefts[l]) {
                --r;
            }

            if (r == n || rights[r] > lefts[l]) {
                ans = min(ans, r - l - 1);
            }

            r = min(r + 1, n);
        }

        return ans;
    }
};

TEST(&Solution::minimumScore)