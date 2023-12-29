#include "leetcode.h"

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for (int i : prices) {
            if (min1 > i) {
                min2 = min1;
                min1 = i;
            }
            else if (min2 > i) {
                min2 = i;
            }
        }

        if (min1 + min2 > money) {
            return money;
        }
        else {
            return money - min1 - min2;
        }
    }
};