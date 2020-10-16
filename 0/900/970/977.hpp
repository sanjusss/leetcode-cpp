#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& A) {
//         vector<int> ans;
//         int n = A.size();
//         int pos = lower_bound(A.begin(), A.end(), 0) - A.begin();
//         if (pos != 0) {
//             int neg = pos - 1;
//             while (neg >= 0 && pos < n) {
//                 if (-A[neg] < A[pos]) {
//                     ans.push_back(A[neg] * A[neg]);
//                     --neg;
//                 }
//                 else {
//                     ans.push_back(A[pos] * A[pos]);
//                     ++pos;
//                 }
//             }

//             while (neg >= 0) {
//                 ans.push_back(A[neg] * A[neg]);
//                 --neg;
//             }
//         }

//         while (pos != n) {
//             ans.push_back(A[pos] * A[pos]);
//             ++pos;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        int i = n - 1;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (abs(A[left]) > abs(A[right])) {
                ans[i] = A[left] * A[left];
                ++left;
            }
            else {                
                ans[i] = A[right] * A[right];
                --right;
            }

            --i;
        }

        ans[0] = A[left] * A[left];
        return ans;
    }
};