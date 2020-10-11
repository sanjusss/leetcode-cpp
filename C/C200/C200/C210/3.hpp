/*
 * @Author: sanjusss
 * @Date: 2020-10-11 10:43:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 11:19:10
 * @FilePath: \C\C200\C200\C210\3.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }

private:
    bool check(const string& a, const string& b) {
        int size = a.size();

        for (int i = 0; i <= size; ++i) {
            if (i > 0 && a[i - 1] != b[size - i]) {
                return check(a, i, size - 1 - i);
            }
            
            if (check(b, i, size - 1 - i)) {
                return true;
            }
        }

        return false;
    }

    bool check(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            }
            else {
                return false;
            }
        }

        return true;
    }
};