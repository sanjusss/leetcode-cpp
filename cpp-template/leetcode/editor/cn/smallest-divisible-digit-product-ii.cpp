/*
 * @lc app=leetcode.cn id=3348 lang=cpp
 * @lcpr version=30404
 *
 * [3348] 最小可整除数位乘积 II
 */

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long w = t;
        for (int i : { 2,3,5,7}) {
            while (w % i == 0) {
                w /= i;
            }
        }

        if (w != 1) {
            return "-1"s;
        } 

        int n = num.size();
        vector<long long> rem(n + 1);
        rem[0] = t;
        int pos = n - 1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                pos = i;
                break;
            }

            rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
        }

        if (rem[n] == 1) {
            return num;
        }

        for (int i = pos; i >= 0; --i) {
            while (++num[i] <= '9') {
                long long w = rem[i] / gcd(rem[i], num[i] - '0');
                int k = 9;
                for (int j = n - 1; j > i; --j) {
                    while (w % k) {
                        --k;
                    }

                    num[j] = k + '0';
                    w /= k;
                }

                if (w == 1) {
                    return num;
                }
            }
        }

        string ans;
        for (int i = 9; i > 1; --i) {
            while (t % i == 0) {
                t /= i;
                ans.push_back(i + '0');
            }
        }

        ans += string(max(0, n + 1 - (int)ans.size()), '1');
        reverse(ans.begin(), ans.end());
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
// "1234"\n256\n
// @lcpr case=end

// @lcpr case=start
// "12355"\n50\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n26\n
// @lcpr case=end

 */

