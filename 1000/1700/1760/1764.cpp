/*
 * @Author: sanjusss
 * @Date: 2022-12-17 10:31:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-17 10:35:05
 * @FilePath: \1000\1700\1760\1764.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (auto& g : groups) {
            bool found = false;
            int m = g.size();
            while (i + m <= n) {
                bool success = true;
                for (int j = 0; j < m; ++j) {
                    if (g[j] != nums[i + j]) {
                        success = false;
                        break;
                    }
                }

                if (success) {
                    i += m;
                    found = true;
                    break;
                }
                else {
                    ++i;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};