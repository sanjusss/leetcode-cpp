/*
 * @lc app=leetcode.cn id=3734 lang=cpp
 * @lcpr version=30404
 *
 * [3734] 大于目标字符串的最小字典序回文排列
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

#include <bits/stdc++.h>


using namespace std;

// @lc code=start
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        const int n = s.size();
        int cnt[26] = {};
        for (char i : s) {
            cnt[i - 'a'] += 1;
        }

        int oddI = -1;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 == 1) {
                if (oddI == -1) {
                    oddI = i;
                } else {
                    return ""s;
                }
            }
        }

        const int half = n / 2;
        const string leftTarget = target.substr(0, half);
        const string leftTargetR(leftTarget.rbegin(), leftTarget.rend());
        const string rightTarget = target.substr(n - half, half);
        const bool needGE =
            (oddI >= 0 && oddI > (target[half] - 'a')) || ((oddI == -1 || oddI == (target[half] - 'a')) && leftTargetR > rightTarget);
        for (int& c : cnt) {
            c /= 2;
        }

        // cout << "half = " << half << endl;
        // cout << "needGE = " << needGE << endl;
        // cout << "oddI = " << oddI << endl;
        // cout << "leftTargetR = " << leftTargetR << endl;
        // cout << "rightTarget = " << rightTarget << endl;

        string ans;
        int prei = -1;  // 前一个大于的索引
        int prek = -1;  // 前一个大于的字母
        bool isGreater = false;
        for (int i = 0; i < half; ++i) {
            int j = leftTarget[i] - 'a';
            int k = j + 1;
            while (k < 26 && cnt[k] == 0) {
                ++k;
            }

            if (cnt[j] == 0) {
                if (k < 26) {
                    isGreater = true;
                    ans.push_back(k + 'a');
                    cnt[k] -= 1;
                }

                break;
            } else {
                ans.push_back(j + 'a');
                cnt[j] -= 1;
                if (k < 26) {
                    prei = i;
                    prek = k;
                }
            }
        }

        if (isGreater) {
            for (int i = 0; i < 26; ++i) {
                while (cnt[i] > 0) {
                    ans.push_back('a' + i);
                    cnt[i] -= 1;
                }
            }
        } else if (needGE && ans.size() == half) {

        } else {
            if (prei == -1) {
                return ""s;
            }

            for (int i = static_cast<int>(ans.size()) - 1; i >= prei; --i) {
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

        if (oddI != -1) {
            ans.push_back('a' + oddI);
        }

        for (int i = half - 1; i >= 0; --i) {
            ans.push_back(ans[i]);
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
// "baba"\n"abba"\n
// @lcpr case=end

// @lcpr case=start
// "baba"\n"bbaa"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abb"\n
// @lcpr case=end

// @lcpr case=start
// "aac"\n"abb"\n
// @lcpr case=end

// @lcpr case=start
// "bb"\n"ba"\n
// @lcpr case=end

// @lcpr case=start
// "abb"\n"bba"\n
// @lcpr case=end


 */
