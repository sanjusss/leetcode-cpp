#include "leetcode.h"

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = 0;
        int maxProfit = 0;
        int curProfit = 0;
        int person = 0;
        int n = customers.size();
        for (int i = 0; i < n || person > 0; ++i) {
            if (i < n) {
                person += customers[i];
            }
            
            int u = min(person, 4);
            person -= u;
            curProfit += u * boardingCost - runningCost;
            if (curProfit > maxProfit) {
                maxProfit = curProfit;
                ans = i + 1;
            }
        }

        return maxProfit > 0 ? ans : -1;
    }
};

TEST(&Solution::minOperationsMaxProfit)