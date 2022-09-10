/*
 * @Author: sanjusss
 * @Date: 2022-09-08 08:59:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-08 09:21:44
 * @FilePath: \0\600\660\667.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int left = 1;
        int right = n;
        while (left < n - k) {
            ans.push_back(left++);
        }

        while (left <= right) {
            ans.push_back(left++);
            if (left <= right) {
                ans.push_back(right--);
            }
        }

        return ans;
    }
};