/*
 * @Author: sanjusss
 * @Date: 2021-08-22 10:08:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 10:09:32
 * @FilePath: \jianzhioffer\40.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == arr.size()) {
            return arr;
        }

        nth_element(arr.begin(), arr.begin() + k, arr.end());
        arr.resize(k);
        return arr;
    }
};