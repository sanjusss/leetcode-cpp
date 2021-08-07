/*
 * @Author: sanjusss
 * @Date: 2021-08-07 10:38:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-07 14:52:50
 * @FilePath: \0\400\450\457.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&n, &nums](int i) {
            return ((nums[i] + i) % n + n) % n;
        };
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }

            int slow = i;
            int fast = next(i);
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    }
                    else {
                        break;
                    }
                }

                slow = next(slow);
                fast = next(next(fast));
            }

            slow = i;
            while (nums[slow] * nums[next(slow)] > 0) {
                nums[slow] = 0;
                slow = next(slow);
            }
        }

        return false;
    }
};

TEST(&Solution::circularArrayLoop)