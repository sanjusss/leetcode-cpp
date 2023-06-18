/*
 * @Author: sanjusss
 * @Date: 2023-06-18 10:29:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-18 11:47:43
 * @FilePath: \C\C300\C350\C350\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int end = 2 * n;
        vector<int> cur(end);
        fill(cur.begin() + n + 1, cur.end(), INT_MAX / 2);
        vector<int> prev(end);
        deque<pair<int, int>> dq;
        for (int i = 0; i < n; ++i) {
            swap(cur, prev);
            for (int j = 1; j < end; ++j) {
                cur[j - 1] = prev[j];
            }

            cur[end - 1] = INT_MAX / 2;

            dq.clear();
            for (int j = 0; j < end; ++j) {
                const int kstop = min(end - 1, j + time[i]);
                int v = prev[j] + cost[i];
                while (!dq.empty() && dq.front().first >= v) {
                    dq.pop_front();
                }

                dq.emplace_front(v, kstop);
                cur[j] = min(cur[j], dq.back().first);
                if (dq.back().second == j) {
                    dq.pop_back();
                }
            }
        }

        return *min_element(cur.begin() + n, cur.end());
    }
};

TEST(&Solution::paintWalls)