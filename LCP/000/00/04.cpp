/*
 * @Author: sanjusss
 * @Date: 2021-09-07 06:36:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-07 06:50:32
 * @FilePath: \LCP\000\00\04.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };
        auto key = [m] (int i, int j) {
            return i * m + j;
        };
        auto pos = [m] (int k, int& i, int& j) {
            i = k / m;
            j = k % m;
        };
        uint64_t all = n * n == 64 ? (UINT64_MAX) : (((uint64_t)1 << (n * m)) - 1);
        uint64_t stop = 0;
        for (auto& b : broken) {
            stop |= key(b[0], b[1]);
        }
        
    }
};