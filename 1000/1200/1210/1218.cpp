/*
 * @Author: sanjusss
 * @Date: 2021-11-05 08:44:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-05 08:50:19
 * @FilePath: \1000\1200\1210\1218.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i : arr) {
            cnt[i] = max(cnt[i], cnt[i - difference] + 1);
            ans = max(ans, cnt[i]);
        }

        return ans;
    }
};