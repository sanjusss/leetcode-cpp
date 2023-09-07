#include "leetcode.h"

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int64_t left = 0;
        int64_t right = (int64_t)(*min_element(ranks.begin(), ranks.end())) * cars * cars;
        while (left < right) {
            int64_t mid = (left + right) / 2;
            int64_t cnt = 0;
            for (int r : ranks) {
                cnt += sqrt(mid / r);
            }

            if (cnt >= cars) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};