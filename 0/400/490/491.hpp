#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        dfs(ans, nums, arr, 0, -1);
        return ans;
    }

private:
    void dfs(vector<vector<int>> &ans, const vector<int>& nums, vector<int>& arr, int cur, int last) {
        if (cur == nums.size()) {
            return;
        }

        if ((arr.empty() || arr.back() <= nums[cur]) && 
            isFirst(nums, cur, last)) {
            arr.push_back(nums[cur]);
            if (arr.size() >= 2) {
                ans.push_back(arr);
            }

            dfs(ans, nums, arr, cur + 1, cur);
            arr.pop_back();
        }

        dfs(ans, nums, arr, cur + 1, last);
    }

    bool isFirst(const vector<int>& nums, int cur, int last) {
        for (int i = last + 1; i < cur; ++i) {
            if (nums[i] == nums[cur]) {
                return false;
            }
        }

        return true;
    }
};