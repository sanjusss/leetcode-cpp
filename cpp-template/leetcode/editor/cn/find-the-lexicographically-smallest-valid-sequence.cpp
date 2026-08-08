/*
 * @lc app=leetcode.cn id=3302 lang=cpp
 * @lcpr version=30404
 *
 * [3302] 字典序最小的合法序列
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

#include <bits/stdc++.h>
#include <vector>


using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        int right = 0;
        vector<int> maxr(m);
        vector<int> suffix(26);
        suffix[word2[n - 1] - 'a'] = 1;
        for (int i = m - 1; i >= 0; --i) {
            if (i + 1 < m) {
                maxr[i] = max(right, maxr[i + 1]);
            }

            right = suffix[word1[i] - 'a'];
            if (right < n) {
                int j = word2[n - 1 - right] - 'a';
                suffix[j] = max(right + 1, suffix[j]);
            }
        }

        vector<int> ans(n);
        int pos = 0;
        bool hasFake = false;
        for (int i = 0; i < m && pos < n; ++i) {
            if (word1[i] == word2[pos]) {
                ans[pos++] = i;
            } else if (!hasFake && maxr[i] >= n - 1 - pos) {
                ans[pos++] = i;
                hasFake = true;
            }
        }

        if (pos != n) {
            return {};
        }

        return ans;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// "vbcca"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "bacdc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "aaaaaa"\n"aaabc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"ab"\n
// @lcpr case=end

 */
