/*
 * @Author: sanjusss
 * @Date: 2022-02-20 18:07:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-20 18:19:55
 * @FilePath: \0\700\710\717.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if (n == 1 || bits[n - 2] == 0) {
            return true;
        }
        
        bool prev = true;
        bool cur = true;
        for (int i = 0; i < n - 2; ++i) {
            bool next = false;
            if (i > 0 && bits[i - 1] == 1) {
                next = next || prev;
            }

            next = next || (bits[i] == 0);
            prev = cur;
            cur = next;
        }

        return !cur;
    }
};