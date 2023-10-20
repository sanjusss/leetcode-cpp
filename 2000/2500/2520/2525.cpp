/*
 * @Author: sanjusss
 * @Date: 2023-10-20 20:13:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-20 20:20:56
 * @FilePath: \2000\2500\2520\2525.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        static constexpr int sc_MaxEdge = 1e4;
        static constexpr int sc_MaxBox = 1e9;
        bool bulky = false;
        bool heavy = false;
        if (length >= 10000 || width >= 10000 || height >= 10000 || (int64_t)length * width * height >= sc_MaxBox) {
            bulky = true;
        }

        if (mass >= 100) {
            heavy = true;
        }

        if (bulky && heavy) {
            return "Both";
        }
        else if (bulky) {
            return "Bulky";
        }
        else if (heavy) {
            return "Heavy";
        }
        else {
            return "Neither";
        }
    }
};