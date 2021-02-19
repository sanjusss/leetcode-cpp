/*
 * @Author: sanjusss
 * @Date: 2021-02-19 09:11:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-19 09:17:01
 * @FilePath: \1000\1000\1000\1004_20210219.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int left = 0;
        int right = 0;
        int zeros = 0;
        while (right < n) {
            if (A[right] == 0) {
                ++zeros;
            }

            if (zeros > K) {
                if (A[left++] == 0) {
                    --zeros;
                }
            }

            ++right;
        }

        return right - left;
    }
};

TEST(&Solution::longestOnes)