/*
 * @Author: sanjusss
 * @Date: 2022-09-15 08:45:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-15 09:02:36
 * @FilePath: \0\600\670\672.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses == 0) {
            return 1;
        }
        else if (n == 1) {
            return 2;
        }
        else if (n == 2) {
            if (presses == 1) {
                return 3;
            }
            else {
                return 4;
            }
        }
        else {
            if (presses == 1) {
                return 4;
            }
            else if (presses == 2) {
                return 7;
            }
            else {
                return 8;
            }
        }
    }
};