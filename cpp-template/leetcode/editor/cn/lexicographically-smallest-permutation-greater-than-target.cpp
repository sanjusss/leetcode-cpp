/*
 * @lc app=leetcode.cn id=3720 lang=cpp
 * @lcpr version=30404
 *
 * [3720] 大于目标字符串的最小字典序排列
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

// @lc code=start
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        const int n = s.size();
        int cnt[26] = {};
        for (char i : s) {
            cnt[i - 'a'] += 1;
        }

        string ans;
        int preg = -1;
        int prek = -1;
        bool success = false;
        for (int i = 0; i < n; ++i) {
            int j = target[i] - 'a';
            int k = j + 1;
            while (k < 26 && cnt[k] == 0) {
                ++k;
            }

            if (cnt[j] > 0) {
                ans.push_back('a' + j);
                cnt[j] -= 1;
                if (k < 26) {
                    preg = i;
                    prek = k;
                }
            } else {
                if (k < 26) {
                    ans.push_back('a' + k);
                    cnt[k] -= 1;
                    success = true;
                }

                break;
            }
        }

        if (success) {
            for (int i = 0; i < 26; ++i) {
                while (cnt[i] > 0) {
                    ans.push_back('a' + i);
                    cnt[i] -= 1;
                }
            }
        } else {
            if (preg == -1) {
                return ""s;
            }

            for (int i = (int)ans.size() - 1; i >= preg; --i) {
                cnt[ans[i] - 'a'] += 1;
                ans.pop_back();
            }

            ans.push_back('a' + prek);
            cnt[prek] -= 1;
            
            for (int i = 0; i < 26; ++i) {
                while (cnt[i] > 0) {
                    ans.push_back('a' + i);
                    cnt[i] -= 1;
                }
            }
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
// "ab"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aab"\n"aab"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"bba"\n
// @lcpr case=end

// @lcpr case=start
// "leet"\n"code"\n
// @lcpr case=end

// @lcpr case=start
// "baba"\n"bbaa"\n
// @lcpr case=end

 */
