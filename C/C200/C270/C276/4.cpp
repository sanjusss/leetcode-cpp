/*
 * @Author: sanjusss
 * @Date: 2022-01-16 10:27:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-16 11:06:49
 * @FilePath: \C\C200\C270\C276\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<>> q;
        for (int i : batteries) {
            q.push(i);
            if (q.size() > n) {
                sum += q.top();
                q.pop();
            }
        }

        long long topCnt = 1;
        while (sum > 0) {
            long long cur = q.top();
            q.pop();
            if (q.empty() || q.top() > cur + sum / topCnt ) {
                cur += sum / topCnt;
                sum = 0;
                q.push(cur);
            }
            else {
                sum -= (q.top() - cur) * topCnt;
                ++topCnt;
            }
        }

        return q.top();
    }
};