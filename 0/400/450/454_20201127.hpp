#pragma once
#include "leetcode.h"

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> cnt;
        for (int i : A) {
            for (int j : B) {
                ++cnt[-i - j];
            }
        }

        int ans = 0;
        for (int i : C) {
            for (int j : D) {
                auto pos = cnt.find(i + j);
                if (pos != cnt.end()) {
                    ans += pos->second;
                }
            }
        }

        return ans;
    }
};