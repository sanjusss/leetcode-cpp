/*
 * @Author: sanjusss
 * @Date: 2021-04-05 15:18:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-05 15:42:38
 * @FilePath: \LCP\20210405\3.cpp
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
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i : nums) {
            if (i < 0) {
                q.push(i);
            }
            else if (i > 0) {
                while (cur < 1) {
                    cur -= q.top();
                    q.pop();
                    ++ans;
                }
            }

            cur += i;
        }

        return ans;
    }
};

TEST(&Solution::magicTower)