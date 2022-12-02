/*
 * @Author: sanjusss
 * @Date: 2022-12-02 08:24:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-02 08:31:31
 * @FilePath: \1000\1700\1760\1769.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        int prev = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            prev += cnt;
            ans[i] += prev;
            cnt += boxes[i] - '0';
        }

        prev = 0;
        cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            prev += cnt;
            ans[i] += prev;
            cnt += boxes[i] - '0';
        }

        return ans;
    }
};

TEST(&Solution::minOperations)