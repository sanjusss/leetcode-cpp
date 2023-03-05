#include "leetcode.h"

class Solution {
public:
    int passThePillow(int n, int time) {
        int turn = 2 + (n - 2) * 2;
        time %= turn;
        ++time;
        if (time > n) {
            return n - (time - n);
        }
        else {
            return time;
        }
    }
};