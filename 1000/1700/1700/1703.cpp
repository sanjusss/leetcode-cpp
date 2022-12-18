/*
 * @Author: sanjusss
 * @Date: 2022-12-18 11:38:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-18 17:10:14
 * @FilePath: \1000\1700\1700\1703.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> zeroSum;
        int preOne = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (preOne == -1) {
                    zeroSum.push_back(0);
                }
                else {
                    int zero = i - preOne - 1;
                    zeroSum.push_back(zeroSum.back() + zero);
                }
                
                preOne = i;
            }
        }

        int cost = 0;

        for (int i = 1; i <= k - 1; ++i) {
            cost += (zeroSum[i] - zeroSum[i - 1]) * min(i, k - i);
        }

        int ans = cost;
        for (int i = k - 1; i + 1 < zeroSum.size(); ++i) {
            int j = i - k + 2;
            int mid = (i + j) / 2;
            cost -= zeroSum[mid] - zeroSum[j - 1];
            cost += zeroSum[i + 1] - zeroSum[mid + k % 2];
            ans = min(cost, ans);
        }

        return ans;
    }
};

TEST(&Solution::minMoves)