/*
 * @Author: sanjusss
 * @Date: 2022-03-02 08:43:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-02 09:30:21
 * @FilePath: \0\500\540\546.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string nearestPalindromic(string n) {
        int64_t in = stoll(n);
        int size = n.size();
        string pal = n;
        for (int i = 0; i < size / 2; ++i) {
            pal[size - 1 - i] = pal[i];
        }

        string smaller = smallerPalindromic(pal);
        int64_t is = stoll(smaller);
        string bigger = biggerPalindromic(pal);
        int64_t ib = stoll(bigger);
        int64_t diff = pal == n ? INT64_MAX : abs(stoll(pal) - in);
        if (abs(is - in) <= diff) {
            diff = abs(is - in);
            pal = smaller;
        }

        if (abs(ib - in) < diff) {
            diff = abs(ib - in);
            pal = bigger;
        }

        return pal;
    }

private:
    string smallerPalindromic(const string& p) {
        string ans = p;
        int size = p.size();
        int end = size / 2 + (size % 2 == 1 ? 0 : -1);
        int i = end;
        while (i >= 0 && ans[i] == '0') {
            --i;
        }

        if (i < 0 || (size > 1 && i == 0 && ans[0] == '1')) {
            ans.pop_back();
            fill(ans.begin(), ans.end(), '9');
        }
        else {
            for (int j = i + 1; j < end; ++j) {
                ans[j] = '9';
                ans[size - 1 - j] = '9';
            }

            ans[size - 1 - i] = --ans[i];
        }

        return ans;
    }

    string biggerPalindromic(const string& p) {
        string ans = p;
        int size = p.size();
        int end = size / 2 + (size % 2 == 1 ? 0 : -1);
        int i = end;
        while (i >= 0 && ans[i] == '9') {
            --i;
        }

        if (i < 0 || (i == 0 && ans[0] == '9')) {
            ans[0] = '1';
            fill(ans.begin() + 1, ans.end(), '0');
            ans.push_back('1');
        }
        else {
            for (int j = i + 1; j < end; ++j) {
                ans[j] = '0';
                ans[size - 1 - j] = '0';
            }

            ans[size - 1 - i] = ++ans[i];
        }

        return ans;
    }
};

TEST(&Solution::nearestPalindromic)