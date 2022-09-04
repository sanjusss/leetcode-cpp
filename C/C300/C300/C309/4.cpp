/*
 * @Author: sanjusss
 * @Date: 2022-08-21 10:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-04 11:07:53
 * @FilePath: \C\C300\C300\C309\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n);
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> q;
        for (int i = 0; i < n; ++i) {
            q.emplace(0, i);
        }

        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        for (auto &meet : meetings) {
            while (q.top().first < meet[0]) {
                auto [start, i] = q.top();
                q.pop();
                q.emplace(meet[0], i);
            }

            auto [start, i] = q.top();
            q.pop();
            ++cnt[i];
            start = max<int64_t>(start, meet[0]) + meet[1] - meet[0];
            q.emplace(start, i);
        }

        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (cnt[i] > cnt[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};