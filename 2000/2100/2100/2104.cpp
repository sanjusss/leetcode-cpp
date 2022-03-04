/*
 * @Author: sanjusss
 * @Date: 2022-03-04 09:10:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-04 09:33:36
 * @FilePath: \2000\2100\2100\2104.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> minS;
        stack<int> maxS;

        vector<int> minLefts(n);
        vector<int> maxLefts(n);
        for (int i = 0; i < n; ++i) {
            while (!minS.empty() && nums[minS.top()] > nums[i]) {
                minS.pop();
            }

            minLefts[i] = minS.empty() ? -1 : minS.top();
            minS.push(i);

            while (!maxS.empty() && nums[maxS.top()] <= nums[i]) {
                maxS.pop();
            }

            maxLefts[i] = maxS.empty() ? -1 : maxS.top();
            maxS.push(i);
        }

        minS = {};
        maxS = {};
        vector<int> minRights(n);
        vector<int> maxRights(n);
        for (int i = n- 1; i >= 0; --i) {
            while (!minS.empty() && nums[minS.top()] >= nums[i]) {
                minS.pop();
            }

            minRights[i] = minS.empty() ? n : minS.top();
            minS.push(i);

            while (!maxS.empty() && nums[maxS.top()] < nums[i]) {
                maxS.pop();
            }

            maxRights[i] = maxS.empty() ? n : maxS.top();
            maxS.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long long)(i - maxLefts[i]) * (maxRights[i] - i) * nums[i];
            ans -= (long long)(i - minLefts[i]) * (minRights[i] - i) * nums[i];
        }

        return ans;
    }
};