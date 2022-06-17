/*
 * @Author: sanjusss
 * @Date: 2022-06-17 08:50:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-17 08:56:11
 * @FilePath: \1000\1000\1080\1089.cpp
 */
#include "leetcode.h"

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int len = 0;
        int lasti = n -1;
        for (int i = 0; i < n; ++i) {
            ++len;
            if (arr[i] == 0) {
                ++len;
            }

            if (len >= n) {
                lasti = i;
                break;
            }
        }

        int j = n - 1;
        for (int i = lasti; i >= 0; --i) {
            if (arr[i] == 0) {
                arr[j--] = 0;
                if (i != lasti || len == n) {
                    arr[j--] = 0;
                }
            }
            else {
                arr[j--] = arr[i];
            }
        }
    }
};