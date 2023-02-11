#include "leetcode.h"

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[2] > amount[0] + amount[1]) {
            return amount[2];
        }
        else {
            return (amount[0] + amount[1] + amount[2] + 1) / 2;
        }
    }
};