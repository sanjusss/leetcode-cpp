/*
 * @Author: sanjusss
 * @Date: 2022-07-31 10:24:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-31 10:40:34
 * @FilePath: \C\C300\C300\C304\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int64_t sum = accumulate(grades.begin(), grades.end(), (int64_t)0);
        sort(grades.begin(), grades.end());
        int group = 1;
        int i = 0;
        while (group * 2 < n - i) {
            int sub = 0;
            for (int j = 0; j < group; ++j) {
                sub += grades[i++];
            }

            if (sub >= sum - sub) {
                break;
            }

            sum -= sub;
            ++group;
        }

        return group;
    }
};

TEST(&Solution::maximumGroups)