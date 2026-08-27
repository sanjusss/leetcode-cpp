/*
 * @lc app=leetcode.cn id=3622 lang=cpp
 * @lcpr version=30404
 *
 * [3622] 判断整除性
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
        for (int i = n; i != 0; i /= 10) {
            sum += i % 10;
            mul *= i % 10;
        }

        return n % (sum + mul) == 0;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// 99\n
// @lcpr case=end

// @lcpr case=start
// 23\n
// @lcpr case=end

 */

