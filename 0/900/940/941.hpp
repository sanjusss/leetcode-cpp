#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     bool validMountainArray(vector<int>& A) {
//         if (A.size() < 3) {
//             return false;
//         }

//         int prev = A.front();
//         bool hasTop = false;
//         int top = 0;
//         for (int i = 1; i < A.size(); ++i) {
//             if (hasTop) {
//                 if (A[i] >= prev) {
//                     return false;
//                 }
//             }
//             else {
//                 if (A[i] == prev) {
//                     return false;
//                 }
//                 else if (A[i] < prev) {
//                     top = prev;
//                     hasTop = true;
//                 }
//             }

//             prev = A[i];
//         }

//         return hasTop && top != A.back() && top != A.front();
//     }
// };

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int i = 0;
        while (i + 1 < n && A[i] < A[i + 1]) {
            ++i;
        }

        if (i == 0 || i == n - 1) {
            return false;
        }

        while (i + 1 < n && A[i] > A[i + 1]) {
            ++i;
        }

        return i == n - 1;
    }
};