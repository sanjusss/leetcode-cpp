/*
 * @Author: sanjusss
 * @Date: 2022-06-28 08:13:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-28 08:34:25
 * @FilePath: \0\300\320\324.cpp
 */
#include "leetcode.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }

        vector<int> cnt(5001);
        for (int i : nums) {
            ++cnt[i];
        }

        int cur = 1;
        for (int i = 5000; i >= 0; --i) {
            while (cnt[i] > 0) {
                --cnt[i];
                nums[cur] = i;
                cur += 2;
                if (cur >= n) {
                    cur = 0;
                }
            }
        }
    }
};