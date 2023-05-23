/*
 * @Author: sanjusss
 * @Date: 2023-05-23 09:10:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-23 09:15:39
 * @FilePath: \1000\1000\1090\1090.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&values](int a, int b) {
            return values[a] > values[b];
        });
        int cnt = 0;
        unordered_map<int, int> use;
        int ans = 0;
        for (int i : is) {
            if (use[labels[i]] >= useLimit) {
                continue;
            }

            ans += values[i];
            ++use[labels[i]];
            if (++cnt >= numWanted) {
                break;
            }
        }

        return ans;
    }
};