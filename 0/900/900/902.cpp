/*
 * @Author: sanjusss
 * @Date: 2022-10-18 08:29:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-18 08:51:12
 * @FilePath: \0\900\900\902.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> nums;
        for (string& i : digits) {
            nums.push_back(i[0] - '0');
        }

        sort(nums.begin(), nums.end());

        vector<int> target;
        while (n > 0) {
            target.push_back(n % 10);
            n /= 10;
        }

        int ans = 0;
        vector<int64_t> base;
        base.push_back(1);
        for (int i = target.size(); i > 1; --i) {
            base.push_back(base.back() * nums.size());
            ans += base.back();
        }

        for (int i = target.size() - 1; i >= 0; --i) {
            int b = target[i];
            auto p = lower_bound(nums.begin(), nums.end(), b);
            ans += (p - nums.begin()) * base[i];
            if (p == nums.end() || *p != b) {
                break;
            }
            else if (i == 0) {
                ++ans;
            }
        }

        return ans;
    }
}; 

TEST(&Solution::atMostNGivenDigitSet)