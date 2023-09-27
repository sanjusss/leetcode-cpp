/*
 * @Author: sanjusss
 * @Date: 2023-09-27 08:52:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-27 09:00:36
 * @FilePath: \1000\1300\1330\1333.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> valids;
        for (auto& r : restaurants) {
            if ((veganFriendly == 0 || r[2] == veganFriendly) && r[3] <= maxPrice && r[4] <= maxDistance) {
                valids.push_back(move(r));
            }
        }

        sort(valids.begin(), valids.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            else {
                return a[1] > b[1];
            }
        });

        vector<int> ans;
        for (auto& r : valids) {
            ans.push_back(r[0]);
        }

        return ans;
    }
};