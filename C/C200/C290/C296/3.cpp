/*
 * @Author: sanjusss
 * @Date: 2022-06-05 10:27:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-05 10:40:08
 * @FilePath: \C\C200\C290\C296\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); ++i) {
            pos[nums[i]] = i;
        }

        for (auto &op : operations) {
            nums[pos[op[0]]] = op[1];
            pos[op[1]] = pos[op[0]];
            pos.erase(op[0]);
        }

        return nums;
    }
};