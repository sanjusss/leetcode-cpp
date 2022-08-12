/*
 * @Author: sanjusss
 * @Date: 2022-08-12 08:11:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-12 08:15:03
 * @FilePath: \1000\1200\1280\1282_20220812.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> sizes;
        for (int i = 0; i < groupSizes.size(); ++i) {
            sizes[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto &[c, arr] : sizes) {
            for (int i = 0; i < arr.size(); ++i) {
                if (i % c == 0) {
                    ans.emplace_back();
                }
                
                ans.back().emplace_back(arr[i]);
            }
        }

        return ans;
    }
};