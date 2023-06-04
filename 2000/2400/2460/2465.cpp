#include "leetcode.h"

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = int(nums.size()) - 1;
        unordered_map<int, int> cnt;
        while (left <= right) {
            ++cnt[nums[left++] + nums[right--]];
        }

        return cnt.size();
    }
};