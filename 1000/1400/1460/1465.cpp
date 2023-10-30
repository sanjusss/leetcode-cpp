#include "leetcode.h"

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        static constexpr int64_t mod = 1e9 + 7;
        int maxH = 0;
        int preH = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        for (int i : horizontalCuts) {
            maxH = max(maxH, i - preH);
            preH = i;
        }

        maxH = max(maxH, h - preH);

        int maxW = 0;
        int preW = 0;
        sort(verticalCuts.begin(), verticalCuts.end());
        for (int i : verticalCuts) {
            maxW = max(maxW, i - preW);
            preW = i;
        }

        maxW = max(maxW, w - preW);
        return (int64_t)maxH * (int64_t)maxW % mod;
    }
};

TEST(&Solution::maxArea)