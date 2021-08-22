/*
 * @Author: sanjusss
 * @Date: 2021-08-22 10:29:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 10:40:22
 * @FilePath: \C\C200\C250\C255\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int end = 1 << n;
        vector<bool> exist(end);
        for (string& i : nums) {
            int s = 0;
            for (char j : i) {
                s <<= 1;
                if (j == '1') {
                    ++s;
                }
            }

            exist[s] = true;
        }

        for (int i = 0; i < end; ++i) {
            if (exist[i]) {
                continue;
            }

            string ans;
            for (int j = n - 1; j >= 0; --j) {
                if (i & (1 << j)) {
                    ans.push_back('1');
                }
                else {
                    ans.push_back('0');
                }
            }

            return ans;
        }

        return ""s;
    }
};