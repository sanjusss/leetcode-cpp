/*
 * @Author: sanjusss
 * @Date: 2021-09-05 10:55:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-05 11:30:30
 * @FilePath: \C\C200\C250\C257\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        static constexpr int64_t mod = 1e9 + 7;
        int n = nextVisit.size();
        vector<int64_t> first(n);
        vector<int64_t> second(n);
        first[0] = 1;
        second[0] = 2;
        for (int i = 1; i < n; ++i) {
            first[i] = (second[i - 1] + 1) % mod;
            second[i] = (first[i] + first[i] - first[nextVisit[i]] + 1) % mod;
        }

        return (first[n - 1] + mod - 1) % mod;
    }
};