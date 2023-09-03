/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-03 10:43:14
 * @FilePath: \C\C300\C360\C361\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int cnt = 0;
        int ans = n;
        for (int i = n - 1; i >= 0; --i) {
            if (cnt == 0) {
                if (num[i] == '0') {
                    ++cnt;
                    ans = min(ans, n - 1);
                }
            }
            else if (cnt == 1) {
                if (num[i] == '0' || num[i] == '5') { // 00 50
                    ans = min(ans, n - i - 2);
                    break;
                }
            }
        }

        cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (cnt == 0) {
                if (num[i] == '5') {
                    ++cnt;
                }
            }
            else if (cnt == 1) {
                if (num[i] == '2' || num[i] == '7') { // 25 75
                    ans = min(ans, n - i - 2);
                    break;
                }
            }
        }

        return ans;
    }
};