/*
 * @Author: sanjusss
 * @Date: 2023-04-02 10:29:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-02 10:44:06
 * @FilePath: \C\C300\C330\C339\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        nth_element(is.begin(), is.begin() + k, is.end(), [&reward1, &reward2](int a, int b) {
            return reward1[a] - reward2[a] > reward1[b] - reward2[b];
        });

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                ans += reward1[is[i]];
            }
            else {
                ans += reward2[is[i]];
            }
        }

        return ans;
    }
};