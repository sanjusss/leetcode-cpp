/*
 * @Author: sanjusss
 * @Date: 2021-08-26 08:22:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-26 08:31:09
 * @FilePath: \0\800\880\881.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int left = 0;
        int right = people.size() - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                ++left;
            }

            --right;
            ++ans;
        }

        return ans;
    }
};

TEST(&Solution::numRescueBoats)