/*
 * @Author: sanjusss
 * @Date: 2021-09-07 06:11:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-07 06:17:46
 * @FilePath: \LCP\000\00\02.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int n = 1;
        int m = cont.back();
        for (int i = cont.size() - 2; i >= 0; --i) {
            n = m * cont[i] + n;
            swap(m, n);
        }
        
        swap(m, n);
        int f = gcd(m, n);
        n /= f;
        m /= f;
        return { n, m };
    }
};

TEST(&Solution::fraction)