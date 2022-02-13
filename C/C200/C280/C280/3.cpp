/*
 * @Author: sanjusss
 * @Date: 2022-02-13 10:56:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-13 11:13:51
 * @FilePath: \C\C200\C280\C280\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        static constexpr int most = 1e5;
        static vector<int> cnt(most + 1);
        static vector<long long> lowCut(most + 1); // 小于时需要减掉的数量
        static vector<long long> highCut(most + 1);// 大于时需要减掉的数量
        fill(cnt.begin(), cnt.end(), 0);
        fill(lowCut.begin(), lowCut.end(), 0);
        fill(highCut.begin(), highCut.end(), 0);
        for (int i : beans) {
            ++cnt[i];
        }

        for (int i = 1; i <= most; ++i) {
            lowCut[i] = lowCut[i - 1] + (long long)cnt[i - 1] * (long long)(i - 1);
        }

        int tempHigh = 0;
        for (int i = most; i > 0; --i) {
            tempHigh += cnt[i];
            highCut[i - 1] = highCut[i] + tempHigh;
        }

        long long ans = INT64_MAX;
        for (int i = 0; i <= most; ++i) {
            ans = min(ans, lowCut[i] + highCut[i]);
        }

        return ans;
    }
};

TEST(&Solution::minimumRemoval)