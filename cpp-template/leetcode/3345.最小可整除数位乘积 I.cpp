/*
 * @lc app=leetcode.cn id=3345 lang=cpp
 * @lcpr version=30404
 *
 * [3345] 最小可整除数位乘积 I
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int smallestNumber(int n, int t) {
        int mul = 1;
        for (int i = n; i != 0; i /= 10) {
            mul *= i % 10;
        }

        if (0 == mul) {
            return n;
        }

        mul /= n % 10;
        for (int i = n % 10; i < 10; ++i) {
            if ((mul * i) % t == 0) {
                return n - (n % 10) + i;
            }
        }

        return n + 10 - (n % 10);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n2\n
// @lcpr case=end

// @lcpr case=start
// 15\n3\n
// @lcpr case=end

 */

