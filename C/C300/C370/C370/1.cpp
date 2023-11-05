/*
 * @Author: sanjusss
 * @Date: 2023-11-05 10:26:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-05 10:32:57
 * @FilePath: \C\C300\C370\C370\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }

        while (q.size() > 1) {
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            if (grid[a][b]) {
                q.push(a);
            }
            else {
                q.push(b);
            }
        }

        return q.front();
    }
};