/*
 * @Author: sanjusss
 * @Date: 2022-02-04 10:11:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-04 10:16:17
 * @FilePath: \0\100\150\159.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        char a = 0;
        char b = 0;
        int lasta = -1;
        int lastb = -1;
        int start = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == a) {
                lasta = i;
            }
            else if (s[i] == b) {
                lastb = i;
            }
            else {
                if (lasta > lastb) {
                    b = s[i];
                    start = lastb + 1;
                    lastb = i;
                }
                else {
                    a = s[i];
                    start = lasta + 1;
                    lasta = i;
                }
            }

            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};