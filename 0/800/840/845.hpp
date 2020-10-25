#pragma once
#include "leetcode.h"

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans = 0;

        int n = A.size();
        int i = 0;
        int start;
        int top;
        while (i < n) {
            start = i;
            while (i < n - 1 && A[i] < A[i + 1]) {
                ++i;
            }

            if (start == i) {
                ++i;
                continue;
            }

            top = i;
            while (i < n - 1 && A[i] > A[i + 1]) {
                ++i;
            }

            if (top == i) {
                ++i;
            }
            else {
                ans = max(ans, i - start + 1);
            }
        }

        return ans;
    }
};