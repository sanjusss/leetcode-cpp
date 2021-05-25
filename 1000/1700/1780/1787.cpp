/*
 * @Author: sanjusss
 * @Date: 2021-05-25 08:18:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-25 09:28:31
 * @FilePath: \1000\1700\1780\1787.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        if (k == 1) {
            return nums.size() - count(nums.begin(), nums.end(), 0);
        }

        vector<unordered_map<int, int>> cnt(k);
        vector<int> size(k);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            ++cnt[i % k][nums[i]];
            ++size[i % k];
        }

        vector<int> cur(1 << 10, INT_MAX / 2);
        vector<int> next(1 << 10);
        cur[0] = 0;
        for (int i = 0; i < k; ++i) {
            fill(next.begin(), next.end(), *min_element(cur.begin(), cur.end()) + size[i]);//next初始化为达到状态j的最大次数
            for (int j = 0; j < (1 << 10); ++j) {
                for (auto& [l, c] : cnt[i]) {
                    next[j ^ l] = min(next[j ^ l], cur[j] + size[i] - c);//当前状态为j，修改为l，导致达到j^l的次数发生变化
                }
            }

            swap(next, cur);
        }

        return cur[0];
    }
};

TEST(&Solution::minChanges)