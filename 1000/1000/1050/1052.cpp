#include "leetcode.h"

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int cur = 0;
        int n = customers.size();
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0 || i < X) {
                cur += customers[i];
            }
        }

        int ans = cur;
        for (int i = X; i < n; ++i) {
            if (grumpy[i - X] == 1) {
                cur -= customers[i - X];
            }

            if (grumpy[i] == 1) {
                cur += customers[i];
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};

TEST(&Solution::maxSatisfied)