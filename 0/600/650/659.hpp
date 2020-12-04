#pragma once
#include "leetcode.h"

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        unordered_map<int, int> ends;
        for (int i : nums) {
            if (cnt[i] == 0) {
                continue;
            }

            --cnt[i];
            if (ends[i - 1] > 0) {
                --ends[i - 1];
                ++ends[i];
            }
            else {
                if (cnt[i + 1] == 0 || cnt[i + 2] == 0) {
                    return false;
                }

                ++ends[i + 2];
                --cnt[i + 1];
                --cnt[i + 2];
            }
        }

        return true;
    }
};