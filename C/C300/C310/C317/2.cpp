/*
 * @Author: sanjusss
 * @Date: 2022-10-30 10:33:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-30 10:44:21
 * @FilePath: \C\C300\C310\C317\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, pair<int64_t, vector<int>>> all;
        int n = creators.size();
        for (int i = 0; i < n; ++i) {
            auto& p = all[creators[i]];
            p.first += views[i];
            p.second.push_back(i);
        }

        vector<vector<string>> ans;
        int64_t maxView = -1;
        for (auto& [creator, p] : all) {
            if (p.first > maxView) {
                maxView = p.first;
                ans.clear();
                ans.push_back({ creator });
            }
            else if (p.first == maxView) {
                ans.push_back({ creator });
            }
        }

        for (auto& r : ans) {
            auto& is = all[r[0]].second;
            auto i = *max_element(is.begin(), is.end(), [&](int a, int b) {
                if (views[a] == views[b]) {
                    return ids[a] > ids[b];
                }
                else {
                    return views[a] < views[b];
                }
            });
            r.push_back(ids[i]);
        }

        return ans;
    }
};