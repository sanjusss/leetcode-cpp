#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = INT_MIN / 2;
        int empty = 0;
        for (int i : prices) {
            int h = max(hold, empty - i);
            int e = max(empty, hold + i - fee);
            hold = h;
            empty = e;
        }

        return empty;
    }
};