/*
 * @Author: sanjusss
 * @Date: 2022-09-19 14:20:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-19 14:25:23
 * @FilePath: \1000\1600\1630\1636.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        sort(nums.begin(), nums.end(), [&cnt](int a, int b) {
            if (cnt[a] == cnt[b]) {
                return a > b;
            }
            else {
                return cnt[a] < cnt[b];
            }
        });

        return nums;
    }
};