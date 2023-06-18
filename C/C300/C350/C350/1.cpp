#include "leetcode.h"

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while (mainTank >= 5 && additionalTank > 0) {
            int f = (mainTank / 5);
            ans += f * 5 * 10;
            mainTank %= 5;
            int add = min(additionalTank, f);
            mainTank += add;
            additionalTank -= add;
        }

        ans += mainTank * 10;
        return ans;
    }
};