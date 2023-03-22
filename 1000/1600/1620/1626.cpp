/*
 * @Author: sanjusss
 * @Date: 2023-03-22 08:36:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-22 09:15:50
 * @FilePath: \1000\1600\1620\1626.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&scores, &ages](int a, int b) {
            if (ages[a] == ages[b]) {
                return scores[a] < scores[b];
            }
            else {
                return ages[a] < ages[b];
            }
        });

        int ans = 0;
        map<int, int> dp;
        for (int i : is) {
            auto p = dp.upper_bound(scores[i]);
            if (p == dp.begin()) {
                dp[scores[i]] = scores[i];
            }
            else {
                int s = prev(p)->second + scores[i];
                dp[scores[i]] = s;
            }

            p = dp.find(scores[i]);
            ans = max(ans, p->second);
            auto q = next(p);
            while (q != dp.end() && q->second <= p->second) {
                q = dp.erase(q);
            }
        }

        return ans;
    }
};