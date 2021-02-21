/*
 * @Author: sanjusss
 * @Date: 2021-02-21 10:18:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-21 10:47:00
 * @FilePath: \C\C200\C220\C229\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> left2right(n);
        vector<int> right2left(n);
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            if (boxes[i - 1] == '1') {
                ++cur;
            }

            left2right[i] = left2right[i - 1] + cur;
        }

        cur = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (boxes[i + 1] == '1') {
                ++cur;
            }

            right2left[i] = right2left[i + 1] + cur;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = left2right[i] + right2left[i];
        }

        return ans;
    }
};

TEST(&Solution::minOperations)