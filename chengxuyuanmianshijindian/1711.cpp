/*
 * @Author: sanjusss
 * @Date: 2022-05-27 08:16:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-27 08:19:44
 * @FilePath: \chengxuyuanmianshijindian\1711.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int w1i = INT_MIN / 2;
        int w2i = INT_MIN / 2;
        int ans = INT_MAX;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i] == word1) {
                w1i = i;
                ans = min(ans, w1i - w2i);
            }
            else if (words[i] == word2) {
                w2i = i;
                ans = min(ans, w2i - w1i);
            }
        }

        return ans;
    }
};