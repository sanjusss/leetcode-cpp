/*
 * @Author: sanjusss
 * @Date: 2023-01-30 11:34:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-30 13:14:43
 * @FilePath: \0\500\560\568.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        vector<int> cur(n, -1);
        cur[0] = 0;
        vector<int> prev(n);
        for (int ki = 0; ki < k; ++ki) {
            swap(prev, cur);
            fill(cur.begin(), cur.end(), -1);
            for (int i = 0; i < n; ++i) {
                if (prev[i] < 0) {
                    continue;
                }

                cur[i] = max(cur[i], prev[i] + days[i][ki]);
                for (int j = 0; j < n; ++j) {
                    if (flights[i][j] == 0) {
                        continue;
                    }

                    cur[j] = max(cur[j], prev[i] + days[j][ki]);
                }
            }
        }
        
        return *max_element(cur.begin(), cur.end());
    }
};

TEST(&Solution::maxVacationDays)