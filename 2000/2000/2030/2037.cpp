/*
 * @Author: sanjusss
 * @Date: 2022-12-31 08:25:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-31 08:26:10
 * @FilePath: \2000\2000\2030\2037.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(seats[i] - students[i]);
        }

        return ans;
    }
};