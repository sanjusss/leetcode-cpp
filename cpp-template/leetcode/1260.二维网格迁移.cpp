/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 * @lcpr version=30404
 *
 * [1260] 二维网格迁移
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        const int total = m * n;
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < total; ++i) {
            int srcX = i / n;
            int srcY = i % n;
            int j = (i + k) % total;
            int desX = j / n;
            int desY = j % n;
            result[desX][desY] = grid[srcX][srcY]; 
        }

        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n9\n
// @lcpr case=end

// @lcpr case=start
// [[1],[2],[3],[4],[7],[6],[5]]\n23\n
// @lcpr case=end

 */

