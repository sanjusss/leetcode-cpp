/*
 * @Author: sanjusss
 * @Date: 2023-09-15 16:41:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-15 16:44:51
 * @FilePath: \LCP\000\50\50.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& o : operations) {
            int diff = gem[o[0]] / 2;
            gem[o[0]] -= diff;
            gem[o[1]] += diff;
        }

        return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
    }
};