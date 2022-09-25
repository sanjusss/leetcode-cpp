/*
 * @Author: sanjusss
 * @Date: 2022-09-25 10:28:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-25 10:52:50
 * @FilePath: \C\C300\C310\C312\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> beforeNG(n);
        vector<int> afterNL(n);

        beforeNG[1] = 1;
        for (int i = 2; i < n; ++i) {
            if (nums[i - 1] > nums[i - 2]) {
                beforeNG[i] = 1;
            }
            else {
                beforeNG[i] = beforeNG[i - 1] + 1;
            }
        }

        afterNL[n - 2] = 1;
        for (int i = n - 3; i >= 0; --i) {
            if (nums[i + 1] > nums[i + 2]) {
                afterNL[i] = 1;
            }
            else {
                afterNL[i] = afterNL[i + 1] + 1;
            }
        }

        vector<int> ans;
        for (int i = k; i < n - k; ++i) {
            if (beforeNG[i] >= k && afterNL[i] >= k) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

TEST(&Solution::goodIndices)