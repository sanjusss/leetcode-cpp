#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int size = A.size();
        if (size == 0) {
            return A;
        }

        int odd = 1;
        int even = 0;
        while (even < size) {
            if (A[even] % 2 == 1) {
                while (A[odd] % 2 == 1) {
                    odd += 2;
                }

                swap(A[even], A[odd]);
                odd += 2;
            }

            even += 2;
        }
        
        return A;
    }
};