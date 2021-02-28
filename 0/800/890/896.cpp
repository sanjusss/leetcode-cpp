/*
 * @Author: sanjusss
 * @Date: 2021-02-28 09:57:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-28 10:00:11
 * @FilePath: \0\800\890\896.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int sign = 0;
        int n = A.size();
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1]) {
                if (sign == -1) {
                    return false;
                }
                else {
                    sign = 1;
                }
            }
            else if (A[i] < A[i - 1]) {
                if (sign == 1) {
                    return false;
                }
                else {
                    sign = -1;
                }
            }
        }
        
        return true;
    }
};

TEST(&Solution::isMonotonic)