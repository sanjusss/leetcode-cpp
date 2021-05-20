/*
 * @Author: sanjusss
 * @Date: 2021-05-20 08:37:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-20 08:54:03
 * @FilePath: \0\600\690\692.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string_view, int> cnt;
        for (auto& w : words) {
            ++cnt[w];
        }

        auto cmp = [&cnt](const pair<string_view, int>& a, const pair<string_view, int>& b){
            if (a.second == b.second) {
                return a.first < b.first;
            }
            else {
                return a.second > b.second;
            }
        };

        priority_queue<pair<string_view, int>, vector<pair<string_view, int>>, decltype(cmp)> q(cmp);
        for (auto& i : cnt) {
            q.push(i);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = q.top().first;
            q.pop();
        }

        return ans;
    }
};

TEST(&Solution::topKFrequent)