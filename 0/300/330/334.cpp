/*
 * @Author: sanjusss
 * @Date: 2022-01-12 09:08:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-12 09:12:02
 * @FilePath: \0\300\330\334.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = 0;
        int a = 0;
        int b = 0;
        for (int i : nums) {
            if (len == 0) {
                a = i;
                len = 1;
            }
            else if (len == 1) {
                if (i > a) {
                    len = 2;
                    b = i;
                }
                else {
                    a = i;
                }
            }
            else {
                if (i > b) {
                    return true;
                }
                else if (i > a) {
                    b = i;
                }
                else {
                    a = i;
                }
            }
        }

        return false;
    }
};