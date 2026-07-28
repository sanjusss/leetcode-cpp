/*
 * @lc app=leetcode.cn id=3517 lang=cpp
 * @lcpr version=30404
 *
 * [3517] 最小回文排列 I
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string smallestPalindrome(string s) {
        int cnts[26] = { };
        for (char i : s) {
            cnts[i - 'a'] += 1;
        }

        int remain = -1;
        string ans;
        for (int i = 0; i < 26; ++i) {
            int c = cnts[i];
            if (c % 2 == 1) {
                remain = i;
            }

            for (int j = c / 2; j > 0; --j) {
                ans.push_back(i  + 'a');
            }
        }

        int k = ans.size();
        if (remain >= 0) {
            ans.push_back(remain + 'a');
        }

        for (; k > 0; --k) {
            ans.push_back(ans[k - 1]);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "z"\n
// @lcpr case=end

// @lcpr case=start
// "babab"\n
// @lcpr case=end

// @lcpr case=start
// "daccad"\n
// @lcpr case=end

 */

