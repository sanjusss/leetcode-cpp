/*
 * @Author: sanjusss
 * @Date: 2021-03-28 10:37:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-28 11:44:45
 * @FilePath: \C\C200\C230\C234\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> arr(n);
        vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }

        int ans = 0;
        while (true) {
            ++ans;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    temp[i] = arr[i / 2];
                }
                else {
                    temp[i] = arr[n / 2 + (i - 1) / 2];
                }
            }

            bool success = true;
            for (int i = 0; i < n; ++i) {
                if (temp[i] != i) {
                    success = false;
                    break;
                }
            }

            if (success) {
                return ans;
            }
            else {
                swap(arr, temp);
            }
        }

        return ans;
    }
};