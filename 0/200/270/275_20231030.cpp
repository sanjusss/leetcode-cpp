#include "leetcode.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (citations[n - mid] >= mid) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

TEST(&Solution::hIndex)