/*
 * @lc app=leetcode.cn id=3016 lang=cpp
 * @lcpr version=30404
 *
 * [3016] 输入单词需要的最少按键次数 II
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumPushes(string word) {
        int cnts[26] = {};
        for (char c : word) {
            cnts[c - 'a'] += 1;
        }

        sort(cnts, cnts + 26);
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += cnts[26 - 1 - i] * ((i + 8) / 8);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n
// @lcpr case=end

// @lcpr case=start
// "xyzxyzxyzxyz"\n
// @lcpr case=end

// @lcpr case=start
// "aabbccddeeffgghhiiiiii"\n
// @lcpr case=end

 */

