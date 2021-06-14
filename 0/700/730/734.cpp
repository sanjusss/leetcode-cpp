/*
 * @Author: sanjusss
 * @Date: 2021-06-14 20:20:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-14 20:23:59
 * @FilePath: \0\700\730\734.cpp
 */
#include "leetcode.h"

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            switch (guess(mid)) {
                case 0:
                    return mid;
                    break;

                case 1:
                    left = mid + 1;
                    break;

                case -1:
                default:
                    right = mid - 1;
                    break;
            }
        }

        return 0;
    }
};