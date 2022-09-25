/*
 * @Author: sanjusss
 * @Date: 2022-09-25 10:28:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-25 10:32:02
 * @FilePath: \C\C300\C310\C312\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&](int a, int b) {
            return heights[a] > heights[b];
        });

        vector<string> ans;
        for (int i : is) {
            ans.push_back(names[i]);
        }

        return ans;
    }
};