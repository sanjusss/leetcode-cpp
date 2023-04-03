/*
 * @Author: sanjusss
 * @Date: 2023-04-03 08:50:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-03 08:55:15
 * @FilePath: \1000\1000\1050\1053.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] <= arr[i + 1]) {
                continue;
            }

            for (int j = n - 1; j > i; --j) {
                if (arr[i] > arr[j] && arr[j] != arr[j - 1]) {
                    swap(arr[i], arr[j]);
                    return arr;
                }
            }
        }

        return arr;
    }
};