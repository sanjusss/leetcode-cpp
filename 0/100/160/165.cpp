/*
 * @Author: sanjusss
 * @Date: 2021-09-01 07:59:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-01 08:15:56
 * @FilePath: \0\100\160\165.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        string_view sv1 = version1;
        string_view sv2 = version2;
        while (!sv1.empty() || !sv2.empty()) {
            int n1 = toInt(sv1);
            int n2 = toInt(sv2);
            if (n1 > n2) {
                return 1;
            }
            else if (n1 < n2) {
                return -1;
            }
        }

        return 0;
    }

private:
    int toInt(string_view& s) {
        int n = 0;
        int cnt = 0;
        for (char i : s) {
            ++cnt;
            if (i == '.') {
                break;
            }

            n *= 10;
            n += i - '0';
        }

        s.remove_prefix(cnt);
        return n;
    }
};

TEST(&Solution::compareVersion)