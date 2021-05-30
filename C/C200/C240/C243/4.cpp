/*
 * @Author: sanjusss
 * @Date: 2021-05-30 10:30:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-30 12:52:07
 * @FilePath: \C\C200\C240\C243\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        auto nan = make_pair(INT_MAX / 2, INT_MAX / 2);
        vector<pair<int, int>> cur(n, nan);
        cur[0] = make_pair(0, 0);
        vector<pair<int, int>> prev(n);
        for (int i = 0; i < n; ++i) {
            swap(cur, prev);
            fill(cur.begin(), cur.end(), nan);
            for (int j = 0; j <= i; ++j) {
                int d = prev[j].first;
                int r = prev[j].second;
                cur[j] = min(cur[j], make_pair((r == 0 ? d : (d + 1)) + dist[i] / speed, dist[i] % speed));
                if (j > 0) {
                    d = prev[j - 1].first + dist[i] / speed;
                    r = prev[j - 1].second + dist[i] % speed;
                    if (r >= speed) {
                        ++d;
                        r -= speed;
                    }

                    cur[j] = min(cur[j], make_pair(d, r));
                }
            }
        }

        auto target = make_pair(hoursBefore, 0);
        for (int i = 0; i < n; ++i) {
            if (cur[i] <= target) {
                return i;
            }
        }

        return -1;
    }
};

TEST(&Solution::minSkips)