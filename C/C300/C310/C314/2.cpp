/*
 * @Author: sanjusss
 * @Date: 2022-10-09 10:38:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-09 10:39:20
 * @FilePath: \C\C300\C310\C314\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        ans[0] = pref[0];
        for (int i = 1; i < n; ++i) {
            ans[i] = pref[i] ^ pref[i - 1];
        }

        return ans;
    }
};