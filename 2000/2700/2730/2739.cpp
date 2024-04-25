#include "leetcode.h"

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank >= 5 && additionalTank > 0) {
            int use = mainTank - mainTank % 5;
            ans += use * 10;
            int add = min(use / 5, additionalTank);
            additionalTank -= add;
            mainTank -= use;
            mainTank += add;
        }

        ans += mainTank * 10;
        return ans;
    }
};