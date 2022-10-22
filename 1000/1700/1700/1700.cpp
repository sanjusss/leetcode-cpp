/*
 * @Author: sanjusss
 * @Date: 2022-10-19 08:49:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-19 08:55:17
 * @FilePath: \1000\1700\1700\1700.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one = 0;
        int zero = 0;
        for (int i : students) {
            if (i == 1) {
                ++one;
            }
            else {
                ++zero;
            }
        }

        for (int i : sandwiches) {
            if (i == 1) {
                if (--one < 0) {
                    break;
                }
            }
            else {
                if (--zero < 0) {
                    break;
                }
            }
        }

        return max(one, 0) + max(zero, 0);
    }
};