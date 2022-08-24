/*
 * @Author: sanjusss
 * @Date: 2022-08-24 08:13:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-24 08:13:34
 * @FilePath: \1000\1400\1460\1460.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};