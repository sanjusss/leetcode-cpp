/*
 * @lc app=leetcode.cn id=3754 lang=cpp
 * @lcpr version=30403
 *
 * [3754] 连接非零数字并乘以其数字和 I
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        long long x10 = 1;
        while (n != 0) {
            int i = n % 10;
            n /= 10;
            if (0 == i) {
                continue;
            }

            sum += i;
            x += x10 * i;
            x10 *= 10;
        }

        return x * sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10203004\n
// @lcpr case=end

// @lcpr case=start
// 1000\n
// @lcpr case=end

 */

