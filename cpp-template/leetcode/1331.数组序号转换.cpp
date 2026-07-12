/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 * @lcpr version=30403
 *
 * [1331] 数组序号转换
 */

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int len = arr.size();
        vector<int> val = arr;
        sort(val.begin(), val.end());
        int i = 0;
        unordered_map<int, int> v2i;
        for (int j = 0; j < len; ++j) {
            if (j == 0 || val[j] != val[j - 1]) {
                v2i[val[j]] = ++i;
            }
        }

        vector<int> out;
        for (int v : arr) {
            out.push_back(v2i[v]);
        }

        return out;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [40,10,20,30]\n
// @lcpr case=end

// @lcpr case=start
// [100,100,100]\n
// @lcpr case=end

// @lcpr case=start
// [37,12,28,9,100,56,80,5,12]\n
// @lcpr case=end

 */

