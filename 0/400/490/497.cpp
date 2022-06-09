/*
 * @Author: sanjusss
 * @Date: 2022-06-09 08:24:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-09 08:41:14
 * @FilePath: \0\400\490\497.cpp
 */
#include "leetcode.h"

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        int total = 0;
        for (auto &r : rects) {
            m_rects[total] = r;
            total += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
        }

        m_dis = uniform_int_distribution<int>{ 0, max(0, total - 1) };
    }
    
    vector<int> pick() {
        int i = m_dis(m_rd);
        auto &[start, r] = *(prev(m_rects.upper_bound(i)));
        i -= start;
        int e = r[3] - r[1] + 1;
        return { { r[0] + i / e, r[1] + i % e } };
    }

private:
    map<int, vector<int>> m_rects;
    random_device m_rd;
    uniform_int_distribution<int> m_dis;
};