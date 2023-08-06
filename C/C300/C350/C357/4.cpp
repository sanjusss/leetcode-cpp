/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-06 11:48:30
 * @FilePath: \C\C300\C350\C357\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [] (const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        unordered_map<int, int> cnt;
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            sum += items[i][0];
            ++cnt[items[i][1]];
        }

        auto cmp = [&items] (int a, int b) {
            return items[a][0] > items[b][0];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i = 0; i < k; ++i) {
            if (cnt[items[i][1]] > 1) {
                q.emplace(i);
            }
        }

        ans = sum + cnt.size() * cnt.size();
        int n = items.size();
        for (int i = k; i < n; ++i) {
            int val = items[i][0];
            int cate = items[i][1];
            if (cnt.count(cate)) {
                continue;
            }

            while (!q.empty() && cnt[items[q.top()][1]] == 1) {
                q.pop();
            }

            if (q.empty()) {
                break;
            }

            --cnt[items[q.top()][1]];
            sum -= items[q.top()][0];
            q.pop();
            ++cnt[cate];
            sum += val;
            ans = max<long long>(ans, sum + cnt.size() * cnt.size());
        }

        return ans;
    }
};