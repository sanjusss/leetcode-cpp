#pragma once
#include "leetcode.h"

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int size = arr.size();
        int len = m * k;
        for (int i = size - len; i >= 0; --i) {
            bool success = true;
            for (int j = m; j < len; ++j) {
                if (arr[i + j % m] != arr[i + j]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                return true;
            }
        }

        return false;
    }
};