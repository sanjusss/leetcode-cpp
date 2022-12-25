/*
 * @Author: sanjusss
 * @Date: 2022-12-25 10:25:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-25 11:04:25
 * @FilePath: \C\C300\C320\C325\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) {
            return 0;
        }

        int n = s.size();
        vector<int> cnt(3);
        for (char i : s) {
            ++cnt[i - 'a'];
        }

        for (int c : cnt) {
            if (c < k) {
                return -1;
            }
        }

        int ans = n;
        int right = 0;  // 第一个不满足的坐标
        for (int left = 0; left < n; ++left) {
            while (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k && right < n) {
                --cnt[s[right++] - 'a'];
            }

            if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
                ans = min(ans, n - (right - left));
            }
            else {
                ans = min(ans, n - (right - left) + 1);
            }

            ++cnt[s[left] - 'a'];
        }

        return ans;
    }
};

TEST(&Solution::takeCharacters)