#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> points(n + 1);
        int prev = rounds[0];
        ++points[prev];
        for (int i = 1; i < rounds.size(); ++i) {
            int cur = rounds[i];
            if (prev > cur) {
                for (int j = prev + 1; j <= n; ++j) {
                    ++points[j];
                }

                for (int j = 1; j <= cur; ++j) {
                    ++points[j];
                }
            }
            else {
                for (int j = prev + 1; j <= cur; ++j) {
                    ++points[j];
                }
            }

            prev = cur;
        }

        int maxValue = *max_element(points.begin(), points.end());
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            if (points[i] == maxValue) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};