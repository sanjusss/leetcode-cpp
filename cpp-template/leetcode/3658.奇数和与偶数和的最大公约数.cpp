/*
 * @lc app=leetcode.cn id=3658 lang=cpp
 * @lcpr version=30404
 *
 * [3658] 奇数和与偶数和的最大公约数
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return gcd((1 + (2 * n  - 1)) * n / 2, (2 + (2 * n)) * n / 2);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

