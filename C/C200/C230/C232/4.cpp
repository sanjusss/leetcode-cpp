/*
 * @Author: sanjusss
 * @Date: 2021-03-14 11:06:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-14 11:42:58
 * @FilePath: \C\C200\C230\C232\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> s;
        vector<int> lefts(n);
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop(); 
            }

            if (s.empty()) {
                lefts[i] = i;
            }
            else {
                if (s.top() + 1 > k) {
                    lefts[i] = -1;
                }
                else {
                    lefts[i] = i - s.top() - 1;
                }
            }

            s.push(i);
        }

        vector<int> rights(n);
        s = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop(); 
            }

            if (s.empty()) {
                rights[i] = n - 1 - i;
            }
            else {
                if (s.top() - 1 < k) {
                    rights[i] = -1;
                }
                else {
                    rights[i] = s.top() - 1 - i;
                }
            }

            s.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (lefts[i] >= 0 && rights[i] >= 0) {
                ans = max(ans, (1 + lefts[i] + rights[i]) * nums[i]);
            }
        }

        return ans;
    }
};

TEST(&Solution::maximumScore)