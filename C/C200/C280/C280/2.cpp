/*
 * @Author: sanjusss
 * @Date: 2022-02-13 10:33:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-13 10:48:04
 * @FilePath: \C\C200\C280\C280\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> cntOdd;
        unordered_map<int, int> cntEven;
        int n = nums.size();
        int totalOdd = 0;
        int totalEven = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                ++cntOdd[nums[i]];
                ++totalOdd;
            }
            else {
                ++cntEven[nums[i]];
                ++totalEven;
            }
        }

        int odd1i = 0;
        int odd1cnt = 0;
        int odd2i = 0;
        int odd2cnt = 0;
        for (auto [i, c] : cntOdd) {
            if (c > odd1cnt) {
                odd2i = odd1i;
                odd2cnt = odd1cnt;
                odd1i = i;
                odd1cnt = c;
            }
            else if (c > odd2cnt) {
                odd2i = i;
                odd2cnt = c;
            }
        }

        int even1i = 0;
        int even1cnt = 0;
        int even2i = 0;
        int even2cnt = 0;
        for (auto [i, c] : cntEven) {
            if (c > even1cnt) {
                even2i = even1i;
                even2cnt = even1cnt;
                even1i = i;
                even1cnt = c;
            }
            else if (c > even2cnt) {
                even2i = i;
                even2cnt = c;
            }
        }

        if (even1i != odd1i) {
            return (totalEven - even1cnt) + (totalOdd - odd1cnt);
        }
        else {
            return min((totalEven - even2cnt) + (totalOdd - odd1cnt), (totalEven - even1cnt) + (totalOdd - odd2cnt));
        }
    }
};