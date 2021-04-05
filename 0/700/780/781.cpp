/*
 * @Author: sanjusss
 * @Date: 2021-04-04 10:21:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-04 10:27:54
 * @FilePath: \0\700\780\781.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (int i : answers) {
            ++cnt[i + 1];
        }

        int ans = 0;
        for (auto& [k, c] : cnt) {
            if (c % k == 0) {
                ans += c;
            }
            else {
                ans += k * (c / k + 1);
            }
        }

        return ans;
    }
};

TEST(&Solution::numRabbits)