/*
 * @Author: sanjusss
 * @Date: 2023-06-02 08:20:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-02 08:25:38
 * @FilePath: \2000\2500\2550\2559.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        static const unordered_set<char> sc_vowels{ 'a', 'e', 'u', 'i', 'o' };
        vector<int> cnt;
        cnt.push_back(0);
        for (auto& w : words) {
            if (sc_vowels.count(w.front()) && sc_vowels.count(w.back())) {
                cnt.push_back(cnt.back() + 1);
            }
            else {
                cnt.push_back(cnt.back());
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(cnt[q[1] + 1] - cnt[q[0]]);
        }

        return ans;
    }
};