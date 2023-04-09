/*
 * @Author: sanjusss
 * @Date: 2023-04-09 12:09:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-09 12:12:53
 * @FilePath: \2000\2300\2390\2399.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        vector<int> prevs(26, -1);
        for (int i = 0; i < n; ++i) {
            int j = s[i] - 'a';
            if (prevs[j] >= 0 && i - prevs[j] - 1 != distance[j]) {
                return false;
            }
            
            prevs[j] = i;
        }

        return true;
    }
};