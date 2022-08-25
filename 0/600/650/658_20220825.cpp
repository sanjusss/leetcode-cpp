/*
 * @Author: sanjusss
 * @Date: 2022-08-25 08:33:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-25 08:39:48
 * @FilePath: \0\600\650\658_20220825.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int end = k;
        while (end < n && (abs(arr[end] - x) < abs(arr[end - k] - x) || arr[end] == arr[end - k])) {
            ++end;
        }

        vector<int> ans;
        copy(arr.begin() + end - k, arr.begin() + end, back_inserter(ans));
        return ans;
    }
};