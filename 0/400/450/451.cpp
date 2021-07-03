/*
 * @Author: sanjusss
 * @Date: 2021-07-03 09:06:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-03 09:14:53
 * @FilePath: \0\400\450\451.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (char i : s) {
            ++cnt[i];
        }

        vector<pair<char, int>> ps(cnt.begin(), cnt.end());
        sort(ps.begin(), ps.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        
        string ans;
        ans.reserve(s.size());
        for (auto& [i, c] : ps) {
            for (int j = 0; j < c; ++j) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};