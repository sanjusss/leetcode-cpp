/*
 * @Author: sanjusss
 * @Date: 2021-08-10 18:07:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-10 18:13:14
 * @FilePath: \jianzhioffer\11.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right && numbers[left] == numbers[right]) {
            ++left;
        }

        if (left == right || numbers[left] < numbers[right]) {
            return numbers[left];
        }

        int begin = numbers[left];
        while (left < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] < begin) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return numbers[left];
    }
};