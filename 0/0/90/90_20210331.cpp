#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        vector<vector<int>> ans(1);
        for (auto& [k, c] : cnt) {
            int n = ans.size();
            for (int i = 0; i < n; ++i) {
                auto arr = ans[i];
                for (int j = 0; j < c; ++j) {
                    arr.push_back(k);
                    ans.push_back(arr);
                }
            }
        }

        return ans;
    }
};

void prepare(vector<vector<int>>& arr, any& _) {
    for (auto& i : arr) {
        sort(i.begin(), i.end());
    }

    sort(arr.begin(), arr.end());
}

TEST_EQUIVALENT_PRE(&Solution::subsetsWithDup, &prepare)