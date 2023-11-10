/*
 * @Author: sanjusss
 * @Date: 2023-11-10 09:51:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-10 09:54:11
 * @FilePath: \2000\2300\2300\2300.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int i : spells) {
            auto p = (success % i == 0) ? lower_bound(potions.begin(), potions.end(), success / i) : upper_bound(potions.begin(), potions.end(), success / i);
            ans.push_back(potions.end() - p);
        }

        return ans;
    }
};