#include "leetcode.h"

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor1 = 0;
        for (int i : arr1) {
            xor1 = xor1 ^ i;
        }

        int xor2 = 0;
        for (int i : arr2) {
            xor2 = xor2 ^ i;
        }

        return xor1 & xor2;
    }
};