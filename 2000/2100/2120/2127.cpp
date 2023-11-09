/*
 * @Author: sanjusss
 * @Date: 2023-11-04 13:58:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-04 14:31:15
 * @FilePath: \2000\2100\2120\2127.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> src(n);
        for (int i = 0; i < n; ++i) {
            ++src[favorite[i]];
        }

        vector<bool> visits(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (src[i] == 0) {
                visits[i] = true;
                q.push(i);
            }
        }

        vector<int> single(n);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            single[favorite[i]] = max(single[favorite[i]], single[i] + 1);
            if (--src[favorite[i]] == 0) {
                visits[favorite[i]] = true;
                q.push(favorite[i]);
            }
        }

        int ans = 1;
        int twinsSum = 0;
        for (int i = 0; i < n; ++i) {
            if (visits[i]) {
                continue;
            }

            int cnt = 0;
            for (int j = i; !visits[j]; j = favorite[j]) {
                ++cnt;
                visits[j] = true;
            }

            if (cnt == 2) {
                twinsSum += 2 + single[i] + single[favorite[i]];
            }

            ans = max(ans, cnt);
        }

        ans = max(ans, twinsSum);
        return ans;
    }
};