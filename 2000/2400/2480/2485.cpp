#include "leetcode.h"

class Solution {
public:
    int pivotInteger(int n) {
        int left = 1;
        int right = n;
        int sum = (1 + n) * n / 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            int sub = mid * mid;
            if (sub == sum) {
                return mid;
            }
            else if (sub > sum) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};