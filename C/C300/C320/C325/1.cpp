/*
 * @Author: sanjusss
 * @Date: 2022-12-25 10:25:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-25 10:34:43
 * @FilePath: \C\C300\C320\C325\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i] != target) {
                continue;
            }

            if (startIndex > i) {
                ans = min(ans, startIndex - i);
                ans = min(ans, i + n - startIndex);
            }
            else {
                ans = min(ans, i - startIndex);
                ans = min(ans, startIndex + n - i);
            }
        }

        if (ans == INT_MAX) {
            return -1;
        }
        else {
            return ans;
        }
    }
};