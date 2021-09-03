/*
 * @Author: sanjusss
 * @Date: 2021-09-03 08:29:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-03 08:36:32
 * @FilePath: \chengxuyuanmianshijindian\1714.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.size() <= k) {
            return arr;
        }

        nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
        arr.resize(k);
        return arr;
    }
};