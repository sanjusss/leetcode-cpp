/*
 * @Author: sanjusss
 * @Date: 2024-02-06 09:09:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-06 09:21:25
 * @FilePath: \LCP\000\30\30.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int magicTower(vector<int>& nums) {
        if (accumulate(nums.begin(), nums.end(), 1ll) <= 0) {
            return -1;
        }

        int ans = 0;
        int64_t cur = 1;
        priority_queue<int, vector<int>, greater<>> q;
        for (int i : nums) {
            q.push(i);
            cur += i;
            while (cur <= 0) {
                cur -= q.top();
                q.pop();
                ++ans;
            }
        }

        return ans;
    }
};