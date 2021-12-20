/*
 * @Author: sanjusss
 * @Date: 2021-12-19 10:15:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-19 11:09:27
 * @FilePath: \C\C200\C270\C272\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> nums;
            int cnt = 0;
            for (int j = i; j < n; j += k) {
                ++cnt;
                auto p = upper_bound(nums.begin(), nums.end(), arr[j]);
                if (p == nums.end()) {
                    nums.push_back(arr[j]);
                }
                else {
                    *p = arr[j];
                }
            }

            ans += cnt - nums.size();
        }

        return ans;
    }
};