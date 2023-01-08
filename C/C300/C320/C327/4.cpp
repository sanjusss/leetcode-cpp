/*
 * @Author: sanjusss
 * @Date: 2023-01-08 10:25:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-08 11:33:47
 * @FilePath: \C\C300\C320\C327\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        auto isFaster = [&](int a, int b) {
            if (time[a][0] + time[a][2] == time[b][0] + time[b][2]) {
                return a < b;
            }
            else {
                return time[a][0] + time[a][2] < time[b][0] + time[b][2];
            }
        };

        priority_queue<int, vector<int>, decltype(isFaster)> qLeft(isFaster);  // 在桥左侧等待的。
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> qNew;  // 在新仓库干活的结束时间，序号
        priority_queue<int, vector<int>, decltype(isFaster)> qRight(isFaster);  // 在桥右侧等待的。
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> qOld;  // 在旧仓库干活的结束时间，序号
        for (int i = 0; i < k; ++i) {
            qLeft.push(i);
        }

        int t = 0;
        int ans = 0;
        while (n > 0) {
            if (qLeft.empty() && qRight.empty()) {
                t = min((qNew.empty() ? INT_MAX : qNew.top().first), (qOld.empty() ? INT_MAX : qOld.top().first));
            }

            while (!qNew.empty() && qNew.top().first <= t) {
                qLeft.push(qNew.top().second);
                qNew.pop();
            }

            while (!qOld.empty() && qOld.top().first <= t) {
                qRight.push(qOld.top().second);
                qOld.pop();
            }

            if (qRight.empty()) {  // 右侧没人等待
                // 必然左侧有人等待
                int i = qLeft.top();
                qLeft.pop();
                t += time[i][0];
                qOld.emplace(t + time[i][1], i);
                --n;
            }
            else {
                int i = qRight.top();
                qRight.pop();
                t += time[i][2];
                ans = max(t, ans);
                qNew.emplace(t + time[i][3], i);
            }
        }

        while (!qOld.empty() || !qRight.empty()) {
            if (qRight.empty()) {
                t = max(t, qOld.top().first);
            }

            while (!qOld.empty() && qOld.top().first <= t) {
                qRight.push(qOld.top().second);
                qOld.pop();
            }

            int i = qRight.top();
            qRight.pop();
            t += time[i][2];
            ans = max(t, ans);
            qNew.emplace(t + time[i][3], i);
        }

        return ans;
    }
};

TEST(&Solution::findCrossingTime)