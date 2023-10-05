#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int ans = 0;
        int hold = INT_MIN; // 持有
        int empty = 0; // 未持有
        int cold = 0; // 冷静期
        for (int i : prices) {
            int h = empty - i;
            int c = hold + i;
            int e = cold;
            hold = max(hold, h);
            empty = max(empty, e);
            cold = max(cold, c);
        }

        return cold;
    }
};