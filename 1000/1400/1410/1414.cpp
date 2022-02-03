/*
 * @Author: sanjusss
 * @Date: 2022-02-03 10:09:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-03 10:12:49
 * @FilePath: \1000\1400\1410\1414.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> arr({ 1, 1 });
        int prev = 1;
        int cur = 1;
        while (cur < k) {
            arr.push_back(cur + prev);
            prev = cur;
            cur = arr.back();
        }

        int ans = 0;
        int i = arr.size() - 1;
        while (k > 0) {
            while (arr[i] > k) {
                --i;
            }

            k -= arr[i];
            ++ans;
        }

        return ans;
    }
};