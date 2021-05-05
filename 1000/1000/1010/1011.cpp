#include "leetcode.h"

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = (left + right) / 2;
            int d = 0;
            int cur = 0;
            for (int i : weights) {
                if (cur + i > mid) {
                    cur = i;
                    ++d;
                }
                else {
                    cur += i;
                }
            }

            if (cur > 0) {
                ++d;
            }

            if (d <= D) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

TEST(&Solution::shipWithinDays)