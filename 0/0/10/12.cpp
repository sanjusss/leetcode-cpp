/*
 * @Author: sanjusss
 * @Date: 2021-05-14 08:28:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-14 08:46:44
 * @FilePath: \0\0\10\12.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string intToRoman(int num) {
        static const unordered_map<int, string> dic = {
            { 1000, "M" },
            { 2000, "MM" },
            { 3000, "MMM" },
            { 100, "C" },
            { 200, "CC" },
            { 300, "CCC" },
            { 400, "CD" },
            { 500, "D" },
            { 600, "DC" },
            { 700, "DCC" },
            { 800, "DCCC" },
            { 900, "CM" },
            { 10, "X" },
            { 20, "XX" },
            { 30, "XXX" },
            { 40, "XL" },
            { 50, "L" },
            { 60, "LX" },
            { 70, "LXX" },
            { 80, "LXXX" },
            { 90, "XC" },
            { 1, "I" },
            { 2, "II" },
            { 3, "III" },
            { 4, "IV" },
            { 5, "V" },
            { 6, "VI" },
            { 7, "VII" },
            { 8, "VIII" },
            { 9, "IX" },
            { 0, "" }
        };
        string ans;
        ans += dic.at(num - num % 1000);
        num %= 1000;
        ans += dic.at(num - num % 100);
        num %= 100;
        ans += dic.at(num - num % 10);
        num %= 10;
        ans += dic.at(num);
        return ans;
    }
};

TEST(&Solution::intToRoman)