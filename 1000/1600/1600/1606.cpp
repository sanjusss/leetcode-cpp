/*
 * @Author: sanjusss
 * @Date: 2022-03-30 08:35:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-30 12:43:30
 * @FilePath: \1000\1600\1600\1606.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> av;
        for (int i = 0; i < k; ++i) {
            av.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freetime;
        vector<int> cnt(k);
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            while (!freetime.empty() && freetime.top().first <= arrival[i]) {
                av.insert(freetime.top().second);
                freetime.pop();
            }

            if (av.empty()) {
                continue;
            }

            auto p = av.lower_bound(i % k);
            if (p == av.end()) {
                p = av.begin();
            }

            ++cnt[*p];
            freetime.emplace(arrival[i] + load[i], *p);
            av.erase(p);
        }

        int maxc = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (cnt[i] == maxc) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};