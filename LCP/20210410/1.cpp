/*
 * @Author: sanjusss
 * @Date: 2021-04-10 14:45:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-10 16:01:16
 * @FilePath: \LCP\20210410\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        if (accumulate(vat.begin(), vat.end(), 0) == 0) {
            return 0;
        }

        auto cmp = [&bucket](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return bucket[a.second] > bucket[b.second];
            }
            else {
                return a.first < b.first;
            }
        };

        int n = bucket.size();
        int base = 0;
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < n; ++i) {
            if (vat[i] == 0) {
                continue;
            }

            if (bucket[i] == 0) {
                ++base;
                ++bucket[i];
            }

            ans = max(ans, (vat[i] - 1) / bucket[i] + 1);
            q.emplace((vat[i] - 1) / bucket[i] + 1, i);
        }

        ans += base;
        while (true) {
            int time = q.top().first;
            if (time == 1) {
                break;
            }

            int total = ans;
            while (q.top().first == time) {
                int i = q.top().second;
                q.pop();
                ++bucket[i];
                ++total;
                q.emplace((vat[i] - 1) / bucket[i] + 1, i);
            }

            total += q.top().first - time;
            if (total > ans) {
                break;
            }
            else {
                ans = total;
            }
        }

        return ans;
    }
};

TEST(&Solution::storeWater)