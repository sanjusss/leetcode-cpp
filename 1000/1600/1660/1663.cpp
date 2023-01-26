/*
 * @Author: sanjusss
 * @Date: 2023-01-26 08:17:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-26 08:20:16
 * @FilePath: \1000\1600\1660\1663.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        while (--n >= 0) {
            if (n * 26 >= k) {
                ans.push_back('a');
                --k;
            }
            else {
                ans.push_back(k - n * 26 + 'a' - 1);
                k = n * 26;
            }
        }

        return ans;
    }
};