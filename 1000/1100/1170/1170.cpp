/*
 * @Author: sanjusss
 * @Date: 2023-06-10 10:20:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-10 10:29:08
 * @FilePath: \1000\1100\1170\1170.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto calc = [] (const string& text) {
            vector<int> cnt(26);
            for (char c : text) {
                ++cnt[c - 'a'];
            }

            for (int i : cnt) {
                if (i > 0) {
                    return i;
                }
            }

            return 0;
        };

        vector<int> cnt;
        for (auto& w : words) {
            cnt.push_back(calc(w));
        }

        sort(cnt.begin(), cnt.end());
        vector<int> ans;
        for (auto& q : queries) {
            int t = calc(q);
            int c = cnt.size() - (upper_bound(cnt.begin(), cnt.end(), t) - cnt.begin());
            ans.push_back(c);
        }

        return ans;
    }
};