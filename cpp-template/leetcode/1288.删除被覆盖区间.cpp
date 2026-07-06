/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 * @lcpr version=30403
 *
 * [1288] 删除被覆盖区间
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (auto &&a, auto &&b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });

        int pre = INT32_MIN;
        int cnt = 0;
        for (auto &&in : intervals) {
            if (in[1] > pre) {
                ++cnt;
                pre = in[1];
            }
        }

        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[3,6],[2,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[34335,39239],[15875,91969],[29673,66453],[53548,69161],[40618,93111]]\n
// @lcpr case=end

 */

