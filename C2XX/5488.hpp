#pragma once
#include "leetcode.h"

class Solution {
public:
    int minOperations(int n) {
        int half = n / 2;
        if (n % 2 == 0) {
            return half * half;
        }
        else {
            return (1 + half) * half;
        }
    }
};