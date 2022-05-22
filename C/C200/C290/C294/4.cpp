/*
 * @Author: sanjusss
 * @Date: 2022-05-22 10:29:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-22 11:51:10
 * @FilePath: \C\C200\C290\C294\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        static constexpr int64_t mod = 1e9 + 7;
        int n = strength.size();
        vector<int64_t> leftSums(n + 1);
        vector<int64_t> leftSums2(n + 1);
        vector<int64_t> rightSums(n + 1);
        vector<int64_t> rightSums2(n + 1);
        stack<int> s;
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            leftSums[i + 1] = (leftSums[i] + strength[i]) % mod;
            leftSums2[i + 1] = (leftSums2[i] + leftSums[i + 1]) % mod;
            int ri = n - 1 - i;
            rightSums[ri] = (rightSums[ri + 1] + strength[ri]) % mod;
            rightSums2[ri] = (rightSums2[ri + 1] + rightSums[ri]) % mod;
        }

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || strength[s.top()] >= strength[i])) {
                int j = s.top();
                s.pop();
                int64_t begin = s.empty() ? 0 : s.top() + 1;
                int64_t back = i - j;
                int64_t prev = j + 1 - begin;
                int64_t right = leftSums2[i] - leftSums2[j];
                right += mod - (back * leftSums[j]) % mod;
                right %= mod;
                right *= prev;
                right %= mod;
                int64_t left = rightSums2[begin] - rightSums2[j + 1];
                left += mod - (prev * rightSums[j]) % mod;
                left %= mod;
                left *= back;
                left %= mod;
                ans += (left + right) * strength[j];
                ans %= mod;
            }

            s.push(i);
        }

        return ans;
    }
};

TEST(&Solution::totalStrength)