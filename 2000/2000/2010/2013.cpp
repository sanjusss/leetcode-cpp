/*
 * @Author: sanjusss
 * @Date: 2022-01-26 09:53:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-26 10:14:09
 * @FilePath: \2000\2000\2010\2013.cpp
 */
#include "leetcode.h"

class DetectSquares {
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        ++m_cnt[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        static const vector<pair<int, int>> dirs = {
            { 1, -1 },
            { 1, 1 },
            { -1, -1 },
            { -1, 1 }
        };
        int ans = 0;
        int x = point[0];
        int y = point[1];
        for (int i = 1; (x - i >= 0 || x + i <= 1000) && (y - i >= 0 || y + i <= 1000); ++i) {
            for (auto [mx, my] : dirs) {
                int tx = x + mx * i;
                int ty = y + my * i;
                if (tx >= 0 && tx <= 1000 && ty >= 0 && ty <= 1000) {
                    ans += m_cnt[tx][ty] * m_cnt[x][ty] * m_cnt[tx][y];
                }
            }
        }

        return ans;
    }

private:
    vector<vector<int>> m_cnt{ 1000 + 1, vector<int>(1000 + 1) };
};