/*
 * @Author: sanjusss
 * @Date: 2021-10-11 08:46:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-11 09:09:16
 * @FilePath: \0\200\270\273.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero"s;
        }

        static const vector<string> thousands = {
            ""s,
            " Thousand"s,
            " Million"s,
            " Billion"s,
        };
        static unordered_map<int, string> nums = {
            { 1, "One"s },      { 2, "Two"s },        { 3, "Three"s },     { 4, "Four"s },      { 5, "Five"s },
            { 6, "Six"s },      { 7, "Seven"s },      { 8, "Eight"s },     { 9, "Nine"s },      { 10, "Ten"s },
            { 11, "Eleven"s },  { 12, "Twelve"s },    { 13, "Thirteen"s }, { 14, "Fourteen"s }, { 15, "Fifteen"s },
            { 16, "Sixteen"s }, { 17, "Seventeen"s }, { 18, "Eighteen"s }, { 19, "Nineteen"s }, { 20, "Twenty"s },
            { 30, "Thirty"s },  { 40, "Forty"s },    { 50, "Fifty"s },    { 60, "Sixty"s },    { 70, "Seventy"s },
            { 80, "Eighty"s },  { 90, "Ninety"s },
        };
        string ans;
        for (auto &t : thousands) {
            if (num == 0) {
                break;
            }

            int r = num % 1000;
            num /= 1000;
            if (r == 0) {
                continue;
            }

            string temp;
            int h = r / 100;
            if (h > 0) {
                temp = nums[h] + " Hundred"s;
            }

            r %= 100;
            if (r > 0) {
                if (!temp.empty()) {
                    temp += " "s;
                }

                if (r > 20) {
                    temp += nums[r - (r % 10)];
                    if (r % 10 > 0) {
                        temp += " "s + nums[r % 10];
                    }
                }
                else {
                    temp += nums[r];
                }
            }

            temp += t;
            if (ans.empty()) {
                ans = temp;
            }
            else {
                ans = temp + " "s + ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::numberToWords)