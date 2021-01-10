#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) {
            return ans;
        }

        int start = nums[0];
        int last = start;
        for (int i = 1; i < nums.size(); ++i) {
            if (last == INT_MAX || last + 1 != nums[i]) {
                if (start == last) {
                    ans.push_back(to_string(start));
                }
                else {
                    ans.push_back(to_string(start) + "->" + to_string(last));
                }

                start = nums[i];
            }

            last = nums[i];
        }

        if (start == last) {
            ans.push_back(to_string(start));
        }
        else {
            ans.push_back(to_string(start) + "->" + to_string(last));
        }

        return ans;
    }
};