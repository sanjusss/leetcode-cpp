/*
 * @Author: sanjusss
 * @Date: 2022-10-31 09:21:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-31 09:25:29
 * @FilePath: \0\400\480\481_20221031.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) {
            return 1;
        }

        vector<int> arr = { 1, 2, 2 };
        int cur = 1;
        int i = 2;
        while (arr.size() < n) {
            arr.push_back(cur);
            if (arr[i] == 2) {
                arr.push_back(cur);
            }

            ++i;
            cur = 3 - cur;
        }

        return count_if(arr.begin(), arr.begin() + n, [] (int i) { return i == 1; });
    }
};